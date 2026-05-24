#include "../vm.hpp"

void vm::stack_vm::push(uint64_t word)
{
    this->stack.push_back(this->get_word(pc));
}
