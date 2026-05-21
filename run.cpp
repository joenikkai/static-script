#include "vm.hpp"

void vm::vm::run()
{
    vm::fetch();
    vm::decode();
    vm::execute();
}
