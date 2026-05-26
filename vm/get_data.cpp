#include "vm.hpp"


/*
  in this file, we are going to decpde the data embeded instde the word
*/

uint64_t vm::vm::get_data(uint64_t word)
{
    return word & DATA_REGION_MASK;
}

