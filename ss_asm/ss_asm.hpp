#ifndef SS_ASM_HPP

#define SS_ASM_HPP

#include "../include/instructions.hpp"
#include <cstdint>

namespace ss_asm 
{
    class ss_asm
    {
    private:
        /* data */
    public:
        ss_asm(/* args */);
        uint64_t make_code(enum types t,);
        ~ss_asm();
    };
    

    
}




#endif // SS_ASM_HPP