#include "vm.hpp"

void vm::register_vm::run()
{
    vm::fetch();
    vm::decode();
    vm::execute();
}

void vm::stack_vm::run()
{
    vm::fetch();
    vm::decode();
    vm::execute();
}
