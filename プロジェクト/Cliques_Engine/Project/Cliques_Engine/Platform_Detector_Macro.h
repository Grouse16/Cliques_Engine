////
// Ú×   FvbgtH[op}N
// à¾   Fhttps://www.yokoweb.net/dokuwiki/programing/c-language/compiler-os-macro-define
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_PLATFORM_DETECTOR_MACRO_H_FILE
#define D_INCLUDE_GUARD_PLATFORM_DETECTOR_MACRO_H_FILE


//  }N  //

//-- EBhEY --//
#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) || defined(__MINGW32__) || defined(__MINGW64__) || defined(_WINDOWS) || defined(_CONSOLE)) && !defined(__CYGWIN__)

// EBhEYOSÅ é±Æð¦·}N
#define D_OS_IS_WINDOWS


//-- }bN --//
#elif defined(__MACH__)

// }bNOSÅ é±Æð¦·}N
#define D_OS_IS_MAC


//-- ibNX --//
#elif defined(__linux__) || defined(__linux)

// ibNXOSÅ é±Æð¦·}N
#define D_OS_IS_LINUX


//-- jbNX --//
#elif defined(__unix__) || defined(__unix) || defined(__CYGWIN__)

// jbNXOSÅ é±Æð¦·}N
#define D_OS_IS_UNIX


//-- msÂ --//
#else

// OSðmÅ«È©Á½±Æð¦·}N
#define D_OS_IS_UNKNOWN

#endif


#endif // !D_INCLUDE_GUARD_PLATFORM_DETECTOR_MACRO_H_FILE


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================



