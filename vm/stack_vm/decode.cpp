#include "../vm.hpp"

void vm::stack_vm::decode()
{
    uint64_t address = this->fetch();
    this->opcode.type = this->get_type(this->get_word(address));
    this->opcode.data = this->get_data(this->get_word(address));
}