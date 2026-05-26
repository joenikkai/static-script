#include "../vm.hpp"
#include <stdexcept>

vm::op_code_type1 vm::stack_vm::pop()
{
    if (this->stack.empty())
        throw std::runtime_error("stack underflow");
    struct op_code_type1 val = this->stack.back();
    this->stack.pop_back();
    return val;
}