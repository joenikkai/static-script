#include "vm.hpp"
#include <iostream>

/*
    in this file we are going to decode the type of data type
*/
uint8_t vm::vm::get_type(uint64_t word)
{
    // we shift the first 56 bits so as to bring forward the last 8 bits then mask the last 8 bits with 256
    // getting these values from global
    return (uint8_t)((word >> DATA_REGION_BITS) & TYPE_REGION_MASK);
}