#include <iostream>
#include "vm/vm.hpp"


#define DEBUG
#undef DEBUG

int main(int argc, char** argv)
{
    std::cout << ("This will be out main entry point\n");
    std::vector<uint64_t> program{0};
    vm::stack_vm s_vm(program);
    s_vm.get_data(1000000000);
    return 0;
}