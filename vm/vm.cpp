#include "vm.hpp"

vm::vm::vm(std::vector<uint64_t> program)
    :program(program),
    running(true)
{
}

vm::vm::~vm()
{
}
