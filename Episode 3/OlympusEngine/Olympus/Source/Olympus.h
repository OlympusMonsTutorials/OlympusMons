#pragma once


#ifdef WIN32

#include <Windows.h>

#endif

#ifdef BUILD_DLL
	#define OLYMPUS_API __declspec(dllexport)
#else
	#define OLYMPUS_API __declspec(dllimport)
#endif