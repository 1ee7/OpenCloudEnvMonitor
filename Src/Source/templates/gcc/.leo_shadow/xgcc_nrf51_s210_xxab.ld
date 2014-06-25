#--unknown-language--@+leo-ver=4-thin
#--unknown-language--@+node:gan0ling.20140624153650.1303:@shadow gcc_nrf51_s210_xxab.ld
#--unknown-language--@@language unknown_language
/* Linker script to configure memory regions. */

SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x0000C000, LENGTH = 0x14000 
  RAM (rwx) :  ORIGIN = 0x20000900, LENGTH = 0x3700 
}


INCLUDE "gcc_nrf51_common.ld"
#--unknown-language--@-node:gan0ling.20140624153650.1303:@shadow gcc_nrf51_s210_xxab.ld
#--unknown-language--@-leo
