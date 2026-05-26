#include "../vm.hpp"

void vm::stack_vm::decode()
{
    uint64_t address = this->fetch();
    this->type = this->get_type(this->get_word(address));
    this->data = this->get_data(this->get_word(address));
}