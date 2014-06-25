//@+leo-ver=4-thin
//@+node:gan0ling.20140624153650.1335:@shadow nrf_nvmc.c
//@@language c
//@@tabwidth -4
//@+others
//@+node:gan0ling.20140624184821.3434:nrf_nvmc_page_erase
/* Copyright (c) 2012 Nordic Semiconductor. All Rights Reserved.
*
* The information contained herein is property of Nordic Semiconductor ASA.
* Terms and conditions of usage are described in detail in NORDIC
* SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT. 
*
* Licensees are granted free, non-transferable use of the information. NO
* WARRANTY of ANY KIND is provided. This heading must NOT be removed from
* the file.
*
* $LastChangedRevision: 17685 $
*/ 

/** 
 *@file
 *@brief NMVC driver implementation 
 */

#include "stdbool.h"
#include "nrf.h"
#include "nrf_nvmc.h"


void nrf_nvmc_page_erase(uint32_t address)
{ 
  // Enable erase.
  NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Een;
  while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
  {
  }

  // Erase the page
  NRF_NVMC->ERASEPAGE = address;
  while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
  {
  }
  
  NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Ren;
  while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
  {
  }
}
//@-node:gan0ling.20140624184821.3434:nrf_nvmc_page_erase
//@+node:gan0ling.20140624184821.3435:nrf_nvmc_write_byte


void nrf_nvmc_write_byte(uint32_t address, uint8_t value)
{
  uint32_t byte_shift = address & (uint32_t)0x03;
  uint32_t address32 = address & ~byte_shift; // Address to the word this byte is in.
  uint32_t value32 = (*(uint32_t*)address32 & ~((uint32_t)0xFF << (byte_shift << (uint32_t)3)));
  value32 = value32 + ((uint32_t)value << (byte_shift << 3));

  // Enable write.
  NRF_NVMC->CONFIG = (NVMC_CONFIG_WEN_Wen << NVMC_CONFIG_WEN_Pos);
  while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
  {
  }

  *(uint32_t*)address32 = value32;
  while(NRF_NVMC->READY == NVMC_READY_READY_Busy)
  {
  }

  NRF_NVMC->CONFIG = (NVMC_CONFIG_WEN_Ren << NVMC_CONFIG_WEN_Pos);
  {
  }
}
//@-node:gan0ling.20140624184821.3435:nrf_nvmc_write_byte
//@+node:gan0ling.20140624184821.3436:nrf_nvmc_write_word

void nrf_nvmc_write_word(uint32_t address, uint32_t value)
{
  // Enable write.
  NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Wen;
  while (NRF_NVMC->READY == NVMC_READY_READY_Busy){
  }

  *(uint32_t*)address = value;
  while (NRF_NVMC->READY == NVMC_READY_READY_Busy){
  }

  NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Ren;
  while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
  {
  }
}
//@-node:gan0ling.20140624184821.3436:nrf_nvmc_write_word
//@+node:gan0ling.20140624184821.3437:nrf_nvmc_write_bytes

void nrf_nvmc_write_bytes(uint32_t address, const uint8_t * src, uint32_t num_bytes)
{
  uint32_t i;
  for(i=0;i<num_bytes;i++)
  {
     nrf_nvmc_write_byte(address+i,src[i]);
  }
}
//@-node:gan0ling.20140624184821.3437:nrf_nvmc_write_bytes
//@+node:gan0ling.20140624184821.3438:nrf_nvmc_write_words

void nrf_nvmc_write_words(uint32_t address, const uint32_t * src, uint32_t num_words)
{
  uint32_t i;

  // Enable write.
  NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Wen;
  while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
  {
  }

  for(i=0;i<num_words;i++)
  {
    ((uint32_t*)address)[i] = src[i];
    while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
    {
    }
  }

  NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Ren;
  while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
  {
  }
}
//@-node:gan0ling.20140624184821.3438:nrf_nvmc_write_words
//@-others

//@-node:gan0ling.20140624153650.1335:@shadow nrf_nvmc.c
//@-leo
