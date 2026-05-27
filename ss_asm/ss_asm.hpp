#ifndef SS_ASM_HPP

#define SS_ASM_HPP

#include "../include/instructions.hpp"
#include <cstdint>
#include <vector>
#include <string>

/**
 * This will search for global start
 */

namespace ss_asm 
{
    enum token_type
    {
        INTEGER,
        FLOAT,
        BOOLEAN,
        CHARACTER,
        STRING,
        END_OF_FILE,
        TOKEN_TYPES_COUNT
    };

    struct token
    {
        std::string value;
        token_type t;
    };
    class ss_asm
    {
        private:
            std::vector<std::string> filenames;

        public:
            ss_asm(/* args */);
            uint64_t make_code(enum types t,uint64_t d);
            virtual std::vector<struct token> lex();
            virtual std::vector<std::string> parse(std::vector<struct token> nodes);
            ~ss_asm();
    };
    

    
}




#endif // SS_ASM_HPP