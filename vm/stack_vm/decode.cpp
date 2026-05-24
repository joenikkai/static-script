#include "../vm.hpp"

void vm::stack_vm::decode()
{
    this->type = this->get_type(this->get_word(this->pc));
    this->data = this->get_data(this->get_word(this->pc));
}