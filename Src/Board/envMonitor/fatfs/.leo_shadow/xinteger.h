//@+leo-ver=4-thin
//@+node:gan0ling.20140624153650.3891:@shadow integer.h
//@@language c
//@@tabwidth -4
//@+others
//@+node:gan0ling.20140624153650.3972:integer declarations
/*-------------------------------------------*/
/* Integer type definitions for FatFs module */
/*-------------------------------------------*/

#ifndef _FF_INTEGER
#define _FF_INTEGER

#ifdef _WIN32	/* FatFs development platform */

#include <windows.h>
#include <tchar.h>

#else			/* Embedded platform */

/* This type MUST be 8 bit */
typedef unsigned char	BYTE;

/* These types MUST be 16 bit */
typedef short			SHORT;
typedef unsigned short	WORD;
typedef unsigned short	WCHAR;

/* These types MUST be 16 bit or 32 bit */
typedef int				INT;
typedef unsigned int	UINT;

/* These types MUST be 32 bit */
typedef long			LONG;
typedef unsigned long	DWORD;

//@-node:gan0ling.20140624153650.3972:integer declarations
//@-others
#endif

#endif
//@-node:gan0ling.20140624153650.3891:@shadow integer.h
//@-leo
