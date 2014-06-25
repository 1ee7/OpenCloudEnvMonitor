//@+leo-ver=4-thin
//@+node:gan0ling.20140624153650.3430:@shadow ble_radio_notification.c
//@@language c
//@@tabwidth -4
//@+others
//@+node:gan0ling.20140624184821.3160:ble_radio_notification declarations
/* Copyright (c) 2012 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */

#include "ble_radio_notification.h"
#include <stdlib.h>


static bool                                 m_radio_active = false;     /**< Current radio state. */
static ble_radio_notification_evt_handler_t m_evt_handler  = NULL;      /**< Application event handler for handling Radio Notification events. */


//@-node:gan0ling.20140624184821.3160:ble_radio_notification declarations
//@+node:gan0ling.20140624184821.3161:SWI1_IRQHandler
void SWI1_IRQHandler(void)
{
    m_radio_active = !m_radio_active;
    if (m_evt_handler != NULL)
    {
        m_evt_handler(m_radio_active);
    }
}
//@-node:gan0ling.20140624184821.3161:SWI1_IRQHandler
//@+node:gan0ling.20140624184821.3162:ble_radio_notification_init


uint32_t ble_radio_notification_init(nrf_app_irq_priority_t               irq_priority,
                                     nrf_radio_notification_distance_t    distance,
                                     ble_radio_notification_evt_handler_t evt_handler)
{
    uint32_t err_code;
    
    m_evt_handler = evt_handler;

    // Initialize Radio Notification software interrupt
    err_code = sd_nvic_ClearPendingIRQ(SWI1_IRQn);
    if (err_code != NRF_SUCCESS)
    {
        return err_code;
    }

    err_code = sd_nvic_SetPriority(SWI1_IRQn, irq_priority);
    if (err_code != NRF_SUCCESS)
    {
        return err_code;
    }

    err_code = sd_nvic_EnableIRQ(SWI1_IRQn);
    if (err_code != NRF_SUCCESS)
    {
        return err_code;
    }

    // Configure the event
    return sd_radio_notification_cfg_set(NRF_RADIO_NOTIFICATION_TYPE_INT_ON_BOTH, distance);
}
//@-node:gan0ling.20140624184821.3162:ble_radio_notification_init
//@-others
//@-node:gan0ling.20140624153650.3430:@shadow ble_radio_notification.c
//@-leo
