#include "../vm.hpp"

void vm::register_vm::run()
{
    register_vm::fetch();
    register_vm::decode();
    register_vm::execute();
}
