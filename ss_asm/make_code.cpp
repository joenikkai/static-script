#include "ss_asm.hpp"

uint64_t ss_asm::ss_asm::make_code(enum types t, uint64_t d)
{
    // uint64_t c = t << DATA_REGION;
    // c += d;
    // return c;
    return (t << DATA_REGION_BITS) + d;
}