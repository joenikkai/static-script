#include "../vm.hpp"

void vm::stack_vm::run()
{
    while (this->isrunning())
    {
        stack_vm::fetch();
        stack_vm::decode();
        stack_vm::execute();
    }
}
