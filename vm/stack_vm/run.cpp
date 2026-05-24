#include "../vm.hpp"

void vm::stack_vm::run()
{
    vm::fetch();
    vm::decode();
    vm::execute();
}
