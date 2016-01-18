#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <math.h>
#include <complex.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <fcntl.h>
#include <getopt.h>
#include <gsl/gsl_linalg.h>
#include <time.h>
#include <dirent.h>
#include <omp.h>

#include "auxi.h"
#include "settings.h"
#include "struct.h"
#include "init.h"
//#include "timer.h"

#include <assert.h>
#if defined(SLEEF)
//#include "sleef-2.80/purec/sleef.h"
#include <sleefsimd.h>
#elif defined(YEPPP)
#include <yepLibrary.h>
#include <yepCore.h>
#include <yepMath.h>
#endif

// Default output and data directories

#ifndef PREFIX
#define PREFIX ./FSTAT_OUT
#endif

#ifndef DTAPREFIX
#define DTAPREFIX .
#endif

// Size of input files
#define ROW 100
#define COL 2


// Fstat function declaration
//long double 
double* Fstatnet(Search_settings *sett, Command_line_opts *opts, Aux_arrays *aux, double *F, double *sgnlo, double *nSource){


	double xa_real = 0., xa_imag = 0., xb_real = 0., xb_imag = 0., xasum_real = 0., xasum_imag = 0., xbsum_real = 0., xbsum_imag = 0.;
	double shft1, cosPH, sinPH, phase[sett->N];
  	double sinalt, cosalt, sindelt, cosdelt;
	int i = 0, n = 0; 
//	double *fstat_out = malloc(10*sizeof(int)); //output
	static double fstat_out[10];
	double aa = 0., bb = 0., aaa = 0., bbb = 0.;
#ifdef YEPPP
//#define VLEN 2048
    int VLEN = sett->N;
    yepLibrary_Init();

    Yep64f _sph[VLEN];
    Yep64f _cph[VLEN];
    enum YepStatus status;

#endif

//From jobcore.c, line 237 
//Loop for each detector 
  	for(n=0; n < sett->nifo; ++n) { 

// Calculate detector positions with respect to baricenter
// Copied from jobcore.c, line 248



		xa_real = 0.;	
		xa_imag = 0.;
		xb_real = 0.;	
		xb_imag = 0.;
		aa = 0.;
		bb = 0.;
//Inside loop
    		for(i=0; i<sett->N; ++i) {

      			ifo[n].sig.shft[i] = nSource[0]*ifo[n].sig.DetSSB[i*3]
		         	+ nSource[1]*ifo[n].sig.DetSSB[i*3+1]
		         	+ nSource[2]*ifo[n].sig.DetSSB[i*3+2];
    
// Phase modulation function
// Copied from jobcore.c, line 265

			phase[i] = sgnlo[0]*(i + ifo[n].sig.shft[i]) 
				+ sgnlo[1]*i*i + (sett->oms 
				+ 2*sgnlo[1]*i)*ifo[n].sig.shft[i];

		}			

		status = yepMath_Cos_V64f_V64f(phase, _cph, VLEN);
		assert(status == YepStatusOk);
		status = yepMath_Sin_V64f_V64f(phase, _sph, VLEN);
		assert(status == YepStatusOk);

// Matched filter 
// Copied from jobcore.c, line 276 and 337


		for (i = 0; i<sett->N; ++i){
			xa_real = xa_real + ifo[n].sig.xDat[i]*ifo[n].sig.aa[i]*_cph[i];
			xa_imag = xa_imag - ifo[n].sig.xDat[i]*ifo[n].sig.aa[i]*_sph[i];
			xb_real = xb_real + ifo[n].sig.xDat[i]*ifo[n].sig.bb[i]*_cph[i];
			xb_imag = xb_imag - ifo[n].sig.xDat[i]*ifo[n].sig.bb[i]*_sph[i];		
			
     			aa += sqr(ifo[n].sig.aa[i]);
      			bb += sqr(ifo[n].sig.bb[i]);
	 
		}	// End of inside loop

    		aaa += aa/ifo[n].sig.sig2; 
    		bbb += bb/ifo[n].sig.sig2;

		xasum_real += xa_real/ifo[n].sig.sig2;	
		xasum_imag += xa_imag/ifo[n].sig.sig2;
		xbsum_real += xb_real/ifo[n].sig.sig2;
		xbsum_imag += xb_imag/ifo[n].sig.sig2;

	}		// End of detector loop

// F - statistic

	fstat_out[5] = - ((( sqr(xasum_real) + sqr(xasum_imag))/aaa)
			+ ((sqr(xbsum_real) +sqr(xbsum_imag))/bbb));

// Amplitude estimates
	fstat_out[0] = 2*xasum_real/aaa;
	fstat_out[1] = 2*xbsum_real/bbb;
	fstat_out[2] = -2*xasum_imag/aaa;
	fstat_out[3] = -2*xbsum_imag/bbb;

// Signal-to-noise ratio
	fstat_out[4] = sqrt(2*(-fstat_out[5]-2));

	fstat_out[6] = sgnlo[0];
	fstat_out[7] = sgnlo[1];
	fstat_out[8] = sgnlo[2];
	fstat_out[9] = sgnlo[3];		


	return fstat_out;
}

int main (int argc, char* argv[]) {

	Search_settings sett;	
	Command_line_opts opts;
  	Search_range s_range; 
  	Aux_arrays aux_arr;
  	double *F; 			// F-statistic array
  	int i, j, r, c, a, b;	 	// myrank, num_threads; 
	int d, o, m;
	double *results;		// Vector with results from Fstatnet function
	long double results_max[10];		  
	double s1, s2, s3, s4;
	double arr[ROW][COL], sgnlo[4], arrg[ROW][COL]; 
	double nSource[3];
  	double sinalt, cosalt, sindelt, cosdelt;

	FILE *gr;
	gr=fopen("./data/sigDif_grid10", "r");
	if (gr !=NULL) {
		for (a = 0; a < ROW; ++a){
			for(b = 0; b < COL; ++b){
				fscanf (gr, "%lf\n", &arrg[a][b]);
			}
		}
	}
	else (puts("Cannot open grid data file"));
	fclose(gr);
	FILE *sig;
	sig=fopen("./data/sigDif_freq10", "r");
	if (sig !=NULL) {
		for (r = 0; r < ROW; ++r){
			for(c = 0; c < COL; ++c){
				fscanf (sig, "%lf\n", &arr[r][c]);
			}
		}
	}
	else (puts("Cannot open freq data file"));
	fclose(sig);

// Command line options 
	handle_opts(&sett, &opts, argc, argv);  
// Output data handling
  	struct stat buffer;

  	if (stat(opts.prefix, &buffer) == -1) {
    		if (errno == ENOENT) {
// Output directory apparently does not exist, try to create one
      			if(mkdir(opts.prefix, S_IRWXU | S_IRGRP | S_IXGRP 
          			| S_IROTH	| S_IXOTH) == -1) {
	      			perror (opts.prefix);
	      			return 1;
      			}
    		} 
		else { // can't access output directory
      			perror (opts.prefix);
      			return 1;
    		}
  	}
// Search settings
  	search_settings(&sett); 
// Detector network settings
  	detectors_settings(&sett, &opts); 
// Array initialization
  	init_arrays(&sett, &opts, &aux_arr, &F);
// Amplitude modulation functions for each detector  
	for(i=0; i<sett.nifo; i++)   
		rogcvir(&ifo[i]); 


// Setting number of using threads (not required)
//omp_set_num_threads(32);

results_max[5] = 0.;

// F - statistic with parallelisation 
#pragma omp parallel private(d, sinalt, cosalt, sindelt, cosdelt, m, o, sgnlo, nSource, results) shared(results_max)
{
#pragma omp for 

		for (d = 0; d < ROW; ++d){

			sgnlo[2] = arrg[d][0];
			sgnlo[3] = arrg[d][1];	

			sinalt = sin(sgnlo[3]);
			cosalt = cos(sgnlo[3]);
			sindelt = sin(sgnlo[2]);
			cosdelt = cos(sgnlo[2]);

			nSource[0] = cosalt*cosdelt;
			nSource[1] = sinalt*cosdelt;
			nSource[2] = sindelt;

			for (o = 0; o < sett.nifo; ++o){
				modvir(sinalt, cosalt, sindelt, cosdelt, 
			   		sett.N, &ifo[o], &aux_arr);  
			}

			for (m = 0; m < ROW; ++m){
				sgnlo[0] = arr[m][0];
				sgnlo[1] = arr[m][1];

				results = Fstatnet(&sett, &opts, &aux_arr, F, sgnlo, nSource);
// Maximum searching
				if(results[5] < results_max[5]){
					for (i = 0; i < 10; i++){
						results_max[i] = results[i];
					}

				}
			}
		}
}

// Output information
	puts("**********************************************************************");
	printf("***	Maximum value of F-statistic is : (-)%Lf	***\n", -results_max[5]);
	printf("Sgnlo: %Le %Le %Le %Le\n", results_max[6], results_max[7], results_max[8], results_max[9]);
	printf("Amplitudes: %Le %Le %Le %Le\n", results_max[0], results_max[1], results_max[2], results_max[3]);
	printf("Signal-to-noise ratio: %Le\n", results_max[4]); 
	puts("**********************************************************************");

// Cleanup & memory free 
//  	cleanup(&sett, &opts, &aux_arr, F);

	return 0;

}

//Test for:
//time LD_LIBRARY_PATH=lib/yeppp-1.0.0/binaries/linux/x86_64 ./followup -data ./data -ident 001 -band 100 -fpo 199.21875 