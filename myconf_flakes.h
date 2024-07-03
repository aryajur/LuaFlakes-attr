/*
** My Configuration file for Lua
*/


#ifndef milconfig_h
#define milconfig_h

/*
** {==================================================================
** Configuration for Paths.
** ===================================================================
*/

/*
@@ LUA_PATH_DEFAULT is the default path that Lua uses to look for
** Lua libraries.
@@ LUA_CPATH_DEFAULT is the default path that Lua uses to look for
** C libraries.
** CHANGE them if your machine has a non-conventional directory
** hierarchy or if you want to install your libraries in
** non-conventional directories.
*/
//#define LUA_VDIR	LUA_VERSION_MAJOR "." LUA_VERSION_MINOR
#if defined(_WIN32) 	/* { */
/*
** In Windows, any exclamation mark ('!') in the path is replaced by the
** path of the directory of the executable file of the current process.
*/
/*
#define LUA_LDIR	"!\\lua\\"
#define LUA_CDIR	"!\\"
#define LUA_SHRDIR	"!\\..\\share\\lua\\" LUA_VDIR "\\"
*/

#undef LUA_PATH_DEFAULT
#define LUA_PATH_DEFAULT  \
		LUA_LDIR"?.lua;"  LUA_LDIR"?\\init.lua;" \
		LUA_CDIR"?.lua;"  LUA_CDIR"?\\init.lua;" \
		LUA_SHRDIR"?.lua;" LUA_SHRDIR"?\\init.lua;" \
		".\\?.lua;" ".\\?\\init.lua;" \
		LUA_CDIR"..\\?\\?.lua;" LUA_CDIR"..\\?\\lua\\?.lua;"
#undef LUA_CPATH_DEFAULT
#define LUA_CPATH_DEFAULT \
		LUA_CDIR"?.dll;" \
		LUA_CDIR"..\\lib\\lua\\" LUA_VDIR "\\?.dll;" \
		LUA_CDIR"loadall.dll;" ".\\?.dll;" LUA_CDIR"?53.dll;"\
		LUA_CDIR"..\\?\\?.dll;"
#else			/* }{ */
/*
#define LUA_ROOT	"/usr/local/"
#define LUA_LDIR	LUA_ROOT "share/lua/" LUA_VDIR "/"
#define LUA_CDIR	LUA_ROOT "lib/lua/" LUA_VDIR "/"
*/
#undef LUA_PATH_DEFAULT
#define LUA_PATH_DEFAULT  \
		LUA_LDIR"?.lua;"  LUA_LDIR"?/init.lua;" \
		LUA_CDIR"?.lua;"  LUA_CDIR"?/init.lua;" \
		"./?.lua;" "./?/init.lua;" \
		"../?/?.lua;" "../?/lua/?.lua;"
#undef LUA_CPATH_DEFAULT
#define LUA_CPATH_DEFAULT \
		LUA_CDIR"?.so;" LUA_CDIR"loadall.so;" "./?.so;"  "./?53.so;" \
		LUA_CDIR"../?/?.so"
#endif			/* } */


// To make file:seek work on files larger than 2GB
// Roberto Suggestion from: http://lua-users.org/lists/lua-l/2015-05/msg00370.html

#if defined(liolib_c) && defined(__MINGW32__)
#include <sys/types.h>

#define l_fseek(f,o,w) fseeko(f,o,w)
#define l_ftell(f) ftello(f)
#define l_seeknum off_t
#endif
  
// Paul Kulchencko suggestion from: http://lua-users.org/lists/lua-l/2015-10/msg00057.html
/*
#if defined(liolib_c) && defined(__MINGW32__)
#include <sys/types.h>
#define l_fseek(f,o,w) fseeko64(f,o,w)
#define l_ftell(f) ftello64(f)
#define l_seeknum off_t
#endif
*/

#endif	// #ifndev milconfig_h

