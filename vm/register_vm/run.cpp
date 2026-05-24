#include "vm.hpp"

void vm::register_vm::run()
{
    vm::fetch();
    vm::decode();
    vm::execute();
}
