#include <iostream>
#include "vm/vm.hpp"
#include "ss_asm/ss_asm.hpp"

#define DEBUG
#undef DEBUG

int main(int argc, char** argv)
{
    ss_asm::ss_asm assembler;
    std::cout << ("This will be out main entry point\n");
    std::vector<uint64_t> program{
        assembler.make_code(types::INSTRUCTIONS, instructions::PUSH),
        assembler.make_code(types::INTEGER, 256),
        assembler.make_code(types::INSTRUCTIONS, instructions::PUSH),
        assembler.make_code(types::CHARACTER, '\n'),
        assembler.make_code(types::INSTRUCTIONS, instructions::WRITE),
        assembler.make_code(types::INSTRUCTIONS, instructions::WRITE),
        assembler.make_code(types::INSTRUCTIONS, instructions::HALT)
    };
    vm::stack_vm ss_vm(program);
#ifdef DEBUG
    for (uint64_t& code:program)
    {
        std::cout << "op code:" << 
        "\n\t| type: " << (uint16_t) ss_vm.get_type(code) << " | "
        "\n\t| data: " << ss_vm.get_data(code) << " | "
        "\n";
    }
#endif // DEBUG
    ss_vm.run();
    return 0;
}