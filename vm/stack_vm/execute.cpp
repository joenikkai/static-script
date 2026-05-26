#include "../vm.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>

#define DEBUG
// #undef DEBUG

void vm::stack_vm::execute()
{
    this->decode();

#ifdef DEBUG
std::cout << "execution cycle: " << 
    "\n\ttype: " << this->type <<
    "\n\tdata: " << this->data <<
    "\n";
#endif // DEBUG

    if (this->type == types::INSTRUCTIONS)
    {
        switch (this->data)
        {
        case instructions::HALT: {
            this->stop();
            break;
        }

        case instructions::PUSH:{
            break;
        }
        case instructions::POP:{
            break;
        }
        case instructions::PUSH_BP:{
            break;
        }
        case instructions::POP_BP:{
            break;
        }
        case instructions::MOV_BP_SP:{
            break;
        }
        case instructions::MOV_SP_BP:{
            break;
        }
        case instructions::SWAP:{
            break;
        }
        case instructions::CALL:{
            break;
        }
        case instructions::RET:{
            break;
        }
        case instructions::LOAD:{
            break;
        }
        case instructions::STORE:{
            break;
        }
        case instructions::WRITE:{
            break;
        }
        case instructions::DP:{
            break;
        }
        case instructions::ADD:{
            break;
        }
        case instructions::SUBTRACT:{
            break;
        }
        case instructions::MULTIPLY:{
            break;
        }
        case instructions::DIVIDE:{
            break;
        }
        case instructions::JMP:{
            break;
        }
        case instructions::JZ:{
            break;
        }
        case instructions::JNZ:{
            break;
        }
        case instructions::CMP_EQ:{
            break;
        }
        case instructions::CMP_NEQ:{
            break;
        }
        case instructions::CMP_GT:{
            break;
        }
        case instructions::CMP_LT:{
            break;
        }
        case instructions::CMP_GT_EQ:{
            break;
        }
        case instructions::CMP_LT_EQ:{
            break;
        }

        default:{
            std::stringstream err;
            err << "Unknown operand. Please check on operand and if you intended for it to be. Add it to the switch case" << 
                "\n\ttype: " << this->type << 
                "\n\tdata: " << this->data << 
                "\n";
            throw std::runtime_error(err.str());
            break;
        }
        }
    }
    else
    {
        return;
    }
}
