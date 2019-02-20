// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _N_SYSTEM_DEFINES_H_
#define _N_SYSTEM_DEFINES_H_

#define _N_EXPORT_
#if defined _N_EXPORT_
#define NAPI __declspec(dllexport)
#else // !_N_EXPORT_
#define NAPI __declspec(dllimport)
#endif // _N_EXPORT_

#define NSL
#define VERSION 1

#define OUT
#define IN
#define OPT_IN
#define OPT_OUT
#define PURE = 0

#endif // !_N_SYSTEM_DEFINES_H_
