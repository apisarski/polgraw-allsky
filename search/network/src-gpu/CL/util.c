// Polgraw includes
#include <CL/util.h>    // function declarations

// Standard C includes
#include <stdio.h>      // printf_s
#include <stdlib.h>     // exit

/// <summary>OpenCL error handling function.</summary>
///
void checkErr(cl_int err, const char * name)
{
    if (err != CL_SUCCESS)
    {
        int count = printf_s("ERROR: %s (%i)\n", name, err);

        exit(err);
    }
}