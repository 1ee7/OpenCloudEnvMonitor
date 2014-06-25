//@+leo-ver=4-thin
//@+node:gan0ling.20140624153650.1346:@shadow nrf_delay.c
//@@language c
//@@tabwidth -4
//@+others
//@+node:gan0ling.20140624184821.3429:nrf_delay_ms
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
 */
 
#include <stdio.h> 
#include "compiler_abstraction.h"
#include "nrf.h"
#include "nrf_delay.h"

/*lint --e{438} "Variable not used" */
void nrf_delay_ms(uint32_t volatile number_of_ms)
{
    while(number_of_ms != 0)
    {
        number_of_ms--;
        nrf_delay_us(999);
    }
}
//@-node:gan0ling.20140624184821.3429:nrf_delay_ms
//@-others
//@-node:gan0ling.20140624153650.1346:@shadow nrf_delay.c
//@-leo
