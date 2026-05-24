#include "vm.hpp"

vm::stack_vm::stack_vm(std::vector<uint64_t> program)
    :vm(program)
{}

vm::stack_vm::~stack_vm()
{
}