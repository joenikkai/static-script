#include "../vm.hpp"

void vm::stack_vm::push()
{
    this->fetch();
    uint64_t data = this->get_word(pc);
    struct op_code_type1 oc{
        .type = get_type(data),
        .data = get_data(data)
    };
    this->stack.push_back(oc);
}
