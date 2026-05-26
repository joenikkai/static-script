#include "../vm.hpp"

void vm::stack_vm::push()
{
    this->stack.push_back(this->get_word(pc));
}
