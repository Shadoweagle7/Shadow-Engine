#ifndef SE_CORE
#define SE_CORE

#ifdef SE_PLATFORM_WINDOWS

#ifdef SE_BUILD_DLL
#define SE_API __declspec(dllexport)
#else
#define SE_API __declspec(dllimport)
#endif // SE_BUILD_DLL

#else
#error Shadow Engine only supports Windows
#endif // SE_PLATFORM_WINDOWS

#define CREATE_BIT_FLAG(x) (1 << x)

#endif // !SE_CORE
