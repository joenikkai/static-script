#include "../vm.hpp"

void vm::register_vm::run()
{
    while(this->isrunning())
    {
        register_vm::fetch();
        register_vm::decode();
        register_vm::execute();
    }
}
