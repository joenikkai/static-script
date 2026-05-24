#include "../vm.hpp"

void vm::stack_vm::run()
{
    stack_vm::fetch();
    stack_vm::decode();
    stack_vm::execute();
}
