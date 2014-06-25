//@+leo-ver=4-thin
//@+node:gan0ling.20140624153650.3980:@shadow unicode.c
//@@language c
//@@tabwidth -4
//@+others
//@-others
#include "../ff.h"

#if _USE_LFN != 0

#if   _CODE_PAGE == 932	/* Japanese Shift_JIS */
#include "cc932.c"
#elif _CODE_PAGE == 936	/* Simplified Chinese GBK */
#include "cc936.c"
#elif _CODE_PAGE == 949	/* Korean */
#include "cc949.c"
#elif _CODE_PAGE == 950	/* Traditional Chinese Big5 */
#include "cc950.c"
#else					/* Small character-set */
#include "ccsbcs.c"
#endif

#endif
//@-node:gan0ling.20140624153650.3980:@shadow unicode.c
//@-leo
