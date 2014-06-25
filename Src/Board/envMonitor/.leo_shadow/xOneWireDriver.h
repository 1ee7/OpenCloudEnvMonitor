//@+leo-ver=4-thin
//@+node:gan0ling.20140625145623.3323:@shadow OneWireDriver.h
//@@language c
//@@tabwidth -4
#ifndef _OneWireDriver_H_
#define _OneWireDriver_H_

#define ONEWIRE_I2C_ADDRESS (0x30)

//@+others
//@+node:gan0ling.20140625145623.3331:Device Reset
/* Command Code     :      F0h 
 * Command Parameter:      None 
 * Description      :      Performs a global reset of device state machine logic. Terminates any ongoing 1-Wire communication. 
 * Typical Use      :      Device initialization after power-up; reinitialization (reset) as desired. 
 * Restriction      :      None (can be executed at any time). 
 * Error Response   :      None 
 * Command Duration :      Maximum 525ns. Counted from falling SCL edge of the command code acknowledge bit. 
 * 1-Wire Activity  :      Ends maximum 262.5ns after the falling SCL edge of the command code acknowledge bit. 
 * Read Pointer Position:  Status Register (for busy polling). 
 * Status Bits Affected :  RST set to 1; 1WB, PPD, SD, SBR, TSB, DIR set to 0. 
 * Configuration Bits Affected:  1WS, APU, SPU set to 0. 
 */

#define ONEWIRE_DEVICE_RESET  (0xF0)

//@-node:gan0ling.20140625145623.3331:Device Reset
//@+node:gan0ling.20140625145623.3332:Set Read Poiner
/* Command Code:  E1h 
 * Command Parameter:  Pointer Code (see Table 1) 
 * Description: Sets the read pointer to the specified register. Overwrites the read pointer position of any 1-Wire  communication command in progress. 
 * Typical Use: To prepare reading the result from a 1-Wire Read Byte command; random read access of registers. 
 * Restriction: None (can be executed at any time).  
 * Error Response: If the pointer code is not valid, the pointer code is not acknowledged and the command is ignored. 
 * Command Duration:  None. The read pointer is updated on the rising SCL edge of the pointer code acknowledge bit. 
 * 1-Wire Activity:  Not affected. 
 * Read Pointer Position:  As specified by the pointer code. 
 * Status Bits Affected:  None 
 * Configuration Bits Affected:  None 
 */
 
#define ONEWIRE_SET_READ_POINTER (0xE1)
#define READ_POINTER_STATUS_REG  (0xF0)
#define READ_POINTER_READ_DATA   (0xE1)
#define READ_POINTER_CFG_REG     (0xC3)

//@-node:gan0ling.20140625145623.3332:Set Read Poiner
//@+node:gan0ling.20140625145623.3333:Write Configuration
/*
 * Command Code:  D2h 
 * Command Parameter:  Configuration Byte 
 * Description: Writes a new configuration byte. The new settings take effect immediately. 
 * Note: When writing to the Configuration Register, the new data is accepted only if the 
 * upper nibble (bits 7 to 4) is the one’s complement of the lower nibble (bits 3 to 0). 
 * When read, the upper nibble is always 0h. 
 * Typical Use:  Defining the features for subsequent 1-Wire communication. 
 * Restriction:  1-Wire activity must have ended before the DS2482-100 can process this command. 
 * Error Response: Command code and parameter are not acknowledged if 1WB = 1 at the time the command 
 * code is received and the command is ignored. 
 * Command Duration: None.The Configuration Register is updated on the rising SCL edge of the configuration-byte acknowledge bit. 
 * 1-Wire Activity:  None 
 * Read Pointer Position:  Configuration Register (to verify write). 
 * Status Bits Affected:  RST set to 0. 
 * Configuration Bits Affected:  1WS, SPU, APU updated. 
 */
 
#define ONEWIRE_WRITE_CFG  (0xD2)
#define CFG_APU_SHIFT      (0)
#define CFG_SPU_SHIFT      (2)
#define CFG_1WS_SHFIT      (3)


//@-node:gan0ling.20140625145623.3333:Write Configuration
//@+node:gan0ling.20140625145623.3334:1-Wire Reset
//@-node:gan0ling.20140625145623.3334:1-Wire Reset
//@+node:gan0ling.20140625145623.3335:1-Wire Single Bit
//@-node:gan0ling.20140625145623.3335:1-Wire Single Bit
//@+node:gan0ling.20140625145623.3336:1-Wire Write Byte
//@-node:gan0ling.20140625145623.3336:1-Wire Write Byte
//@+node:gan0ling.20140625145623.3337:1-Wire Read Byte
//@-node:gan0ling.20140625145623.3337:1-Wire Read Byte
//@+node:gan0ling.20140625145623.3338:1-Wire Triplet
//@-node:gan0ling.20140625145623.3338:1-Wire Triplet
//@-others

#endif
//@nonl
//@-node:gan0ling.20140625145623.3323:@shadow OneWireDriver.h
//@-leo
