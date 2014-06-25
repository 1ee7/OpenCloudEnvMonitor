//@+leo-ver=4-thin
//@+node:gan0ling.20140624153650.3717:@shadow ble_advdata_parser.h
//@@language c
//@@tabwidth -4
//@+others
//@-others
#ifndef BLE_ADVDATA_PARSER_H_
#define BLE_ADVDATA_PARSER_H_

#include "ble_advdata.h"

uint32_t ble_advdata_parse(uint8_t * p_data, uint8_t len, ble_advdata_t * advdata);
uint32_t ble_advdata_parser_field_find(uint8_t type, uint8_t * p_advdata, uint8_t * len, uint8_t ** pp_field_data);

#endif
//@-node:gan0ling.20140624153650.3717:@shadow ble_advdata_parser.h
//@-leo
