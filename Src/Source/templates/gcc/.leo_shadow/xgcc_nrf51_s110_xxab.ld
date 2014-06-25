#--unknown-language--@+leo-ver=4-thin
#--unknown-language--@+node:gan0ling.20140624153650.1299:@shadow gcc_nrf51_s110_xxab.ld
#--unknown-language--@@language unknown_language
/* Linker script to configure memory regions. */

SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x00014000, LENGTH = 0xC000 
  RAM (rwx) :  ORIGIN = 0x20002000, LENGTH = 0x2000 
}


INCLUDE "gcc_nrf51_common.ld"
#--unknown-language--@-node:gan0ling.20140624153650.1299:@shadow gcc_nrf51_s110_xxab.ld
#--unknown-language--@-leo
