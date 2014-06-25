#--unknown-language--@+leo-ver=4-thin
#--unknown-language--@+node:gan0ling.20140624153650.1296:@shadow gcc_nrf51_blank_xxab.ld
#--unknown-language--@@language unknown_language
/* Linker script to configure memory regions. */

SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x20000
  RAM (rwx) :  ORIGIN = 0x20000000, LENGTH = 0x4000
}


INCLUDE "gcc_nrf51_common.ld"
#--unknown-language--@-node:gan0ling.20140624153650.1296:@shadow gcc_nrf51_blank_xxab.ld
#--unknown-language--@-leo
