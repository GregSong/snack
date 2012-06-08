#ifndef _SNACK_MACRO_H
#define _SNACK_MACRO_H

#define SNACK_SUCCESS 0
#define SNACK_FAILURE 1

#ifndef TRUE
#define TRUE 0
#endif // TRUE

#ifndef FALSE
#define FALSE 1
#endif // FALSE

#define IN
#define OUT

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_DLL
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__((dllexport))
    #else
      #define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__((dllimport))
    #else
      #define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define DLL_PUBLIC __attribute__((visibility ("default")))
    #define DLL_LOCAL  __attribute__((visibility ("hidden")))
  #else
    #define DLL_PUBLIC
    #define DLL_LOCAL
  #endif
#endif

#define DLLEXPORT __attribute__((visibility("default")))

#endif // _SNACK_MACRO_H
