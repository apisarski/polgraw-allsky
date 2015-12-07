/*
 *                       Yeppp! library implementation
 *                   This file is auto-generated by Peach-Py,
 *        Portable Efficient Assembly Code-generator in Higher-level Python,
 *                  part of the Yeppp! library infrastructure
 * This file is part of Yeppp! library and licensed under the New BSD license.
 * See LICENSE.txt for the full text of the license.
 */

#pragma once

#include <yepPredefines.h>
#include <yepTypes.h>
#include <yepPrivate.h>
#include <yepCore.h>
#include <library/functions.h>

extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(const Yep8s *YEP_RESTRICT, Yep8s *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_V8s_V8s[];
extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(const Yep16s *YEP_RESTRICT, Yep16s *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_V16s_V16s[];
extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(const Yep32s *YEP_RESTRICT, Yep32s *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_V32s_V32s[];
extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(const Yep64s *YEP_RESTRICT, Yep64s *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_V64s_V64s[];
extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(const Yep32f *YEP_RESTRICT, Yep32f *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_V32f_V32f[];
extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(const Yep64f *YEP_RESTRICT, Yep64f *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_V64f_V64f[];
extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(Yep8s *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_IV8s_IV8s[];
extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(Yep16s *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_IV16s_IV16s[];
extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(Yep32s *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_IV32s_IV32s[];
extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(Yep64s *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_IV64s_IV64s[];
extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(Yep32f *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_IV32f_IV32f[];
extern "C" YEP_PRIVATE_SYMBOL const FunctionDescriptor<YepStatus (YEPABI*)(Yep64f *YEP_RESTRICT, YepSize)> _dispatchTable_yepCore_Negate_IV64f_IV64f[];

extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_V8s_V8s)(const Yep8s *YEP_RESTRICT xPointer, Yep8s *YEP_RESTRICT yPointer, YepSize length);
extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_V16s_V16s)(const Yep16s *YEP_RESTRICT xPointer, Yep16s *YEP_RESTRICT yPointer, YepSize length);
extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_V32s_V32s)(const Yep32s *YEP_RESTRICT xPointer, Yep32s *YEP_RESTRICT yPointer, YepSize length);
extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_V64s_V64s)(const Yep64s *YEP_RESTRICT xPointer, Yep64s *YEP_RESTRICT yPointer, YepSize length);
extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_V32f_V32f)(const Yep32f *YEP_RESTRICT xPointer, Yep32f *YEP_RESTRICT yPointer, YepSize length);
extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_V64f_V64f)(const Yep64f *YEP_RESTRICT xPointer, Yep64f *YEP_RESTRICT yPointer, YepSize length);
extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_IV8s_IV8s)(Yep8s *YEP_RESTRICT vPointer, YepSize length);
extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_IV16s_IV16s)(Yep16s *YEP_RESTRICT vPointer, YepSize length);
extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_IV32s_IV32s)(Yep32s *YEP_RESTRICT vPointer, YepSize length);
extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_IV64s_IV64s)(Yep64s *YEP_RESTRICT vPointer, YepSize length);
extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_IV32f_IV32f)(Yep32f *YEP_RESTRICT vPointer, YepSize length);
extern "C" YEP_PRIVATE_SYMBOL YepStatus (YEPABI* _yepCore_Negate_IV64f_IV64f)(Yep64f *YEP_RESTRICT vPointer, YepSize length);

inline static YepStatus _yepCore_Negate_Init() {
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_V8s_V8s) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_V8s_V8s);
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_V16s_V16s) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_V16s_V16s);
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_V32s_V32s) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_V32s_V32s);
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_V64s_V64s) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_V64s_V64s);
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_V32f_V32f) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_V32f_V32f);
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_V64f_V64f) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_V64f_V64f);
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_IV8s_IV8s) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_IV8s_IV8s);
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_IV16s_IV16s) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_IV16s_IV16s);
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_IV32s_IV32s) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_IV32s_IV32s);
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_IV64s_IV64s) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_IV64s_IV64s);
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_IV32f_IV32f) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_IV32f_IV32f);
	*reinterpret_cast<FunctionPointer*>(&_yepCore_Negate_IV64f_IV64f) = _yepLibrary_InitFunction((const FunctionDescriptor<YepStatus (*)()>*)_dispatchTable_yepCore_Negate_IV64f_IV64f);
	return YepStatusOk;
}