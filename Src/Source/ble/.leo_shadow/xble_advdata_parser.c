//@+leo-ver=4-thin
//@+node:gan0ling.20140624153650.3005:@shadow ble_advdata_parser.c
//@@language c
//@@tabwidth -4
//@+others
//@+node:gan0ling.20140624184821.3080:ble_advdata_parser_field_find
#include "ble_advdata_parser.h"

uint32_t ble_advdata_parser_field_find(uint8_t type, uint8_t * p_advdata, uint8_t * len, uint8_t ** pp_field_data)
{
    uint32_t index = 0;
    
    while (index < *len)
    {
        uint8_t field_length = p_advdata[index];
        uint8_t field_type = p_advdata[index+1];
        
        if (field_type == type)
        {
            *pp_field_data = &p_advdata[index+2];
            *len = field_length-1;
            return NRF_SUCCESS;
        }
        index += field_length+1;
    }
    return NRF_ERROR_NOT_FOUND;
}
//@-node:gan0ling.20140624184821.3080:ble_advdata_parser_field_find
//@-others
//@-node:gan0ling.20140624153650.3005:@shadow ble_advdata_parser.c
//@-leo
