#include <iostream>
#include "vm/vm.hpp"


#define DEBUG
#undef DEBUG

int main(int argc, char** argv)
{
    std::vector<uint64_t> program{
        ss_asm::ss_asm::make_code(types::INSTRUCTIONS, instructions::PUSH),
        ss_asm::ss_asm::make_code(types::INTEGER, 256),
        ss_asm::ss_asm::make_code(types::INSTRUCTIONS, instructions::PUSH),
        ss_asm::ss_asm::make_code(types::CHARACTER, '\n'),
        ss_asm::ss_asm::make_code(types::INSTRUCTIONS, instructions::WRITE),
        ss_asm::ss_asm::make_code(types::INSTRUCTIONS, instructions::WRITE),
        ss_asm::ss_asm::make_code(types::INSTRUCTIONS, instructions::HALT)};
    std::cout << ("This will be out main entry point\n");
    std::vector<uint64_t> program{0};
    vm::stack_vm s_vm(program);
    s_vm.get_data(1000000000);
    return 0;
}