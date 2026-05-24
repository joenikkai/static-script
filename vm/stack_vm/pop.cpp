#include "../vm.hpp"
#include <stdexcept>

uint64_t vm::stack_vm::pop()
{
    if (this->stack.empty())
        throw std::runtime_error("stack underflow");
    uint64_t val = this->stack.back();
    this->stack.pop_back();
    return val;
}