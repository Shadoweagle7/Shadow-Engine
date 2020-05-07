#ifndef SE7_CORE
#define SE7_CORE

#ifdef SE7_WINDOWS

#ifdef SE7_DLL
#define SE7_API __declspec(dllexport)
#else
#define SE7_API __declspec(dllimport)
#endif // SE7_DLL

#else
#error Windows is currently the only supported platform.
#endif // Windows
#endif // !SE7_CORE
