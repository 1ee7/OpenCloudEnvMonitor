//@+leo-ver=4-thin
//@+node:gan0ling.20140624153650.1348:@shadow nrf_assert.c
//@@language c
//@@tabwidth -4
//@+others
//@+node:gan0ling.20140624184821.3428:assert_nrf_callback
/* Copyright (c) 2006 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */
#include "nrf_assert.h"

#if defined(DEBUG_NRF)
void assert_nrf_callback(uint16_t line_num, const uint8_t *file_name)
{
  (void) file_name; /* Unused parameter */
  (void) line_num; /* Unused parameter */
 
  while (1) ;
}
//@-node:gan0ling.20140624184821.3428:assert_nrf_callback
//@-others
#endif /* DEBUG_NRF */
//@-node:gan0ling.20140624153650.1348:@shadow nrf_assert.c
//@-leo
