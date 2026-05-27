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
    "\n\ttype: " << (uint16_t)this->opcode.type <<
    "\n\tdata: " << this->opcode.data <<
    "\n";
#endif // DEBUG

    if (this->opcode.type == types::INSTRUCTIONS)
    {
        switch (this->opcode.data)
        {
        case instructions::HALT: {
            this->stop();
            break;
        }

        case instructions::PUSH:{
            this->push();
            break;
        }
        case instructions::POP:{
            (this->pop());
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
            switch (this->opcode.type)
            {
                case types::CHARACTER:
                {
                    std::cout << (unsigned char)this->stack.back().data;
                    break;
                }

                case types::ADDRESS:
                {
                    std::cout << "0x"<< std::hex<<this->stack.back().data;
                    break;
                }
                default:
                {
                    std::cout << this->stack.back().data;
                    break;
                }
            }
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
                "\n\ttype: " << (uint16_t)this->opcode.type << 
                "\n\tdata: " << this->opcode.data << 
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
