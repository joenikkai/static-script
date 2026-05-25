#include "../vm.hpp"

uint64_t vm::stack_vm::fetch()
{
    return this->pc++;
}
