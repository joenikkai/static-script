#ifndef VM_HPP
#define VM_HPP
#include <cstdint>
#include <vector>

namespace vm
{
    typedef uint64_t u64;
    class vm
    {
    private:
        std::vector<u64> program;

    public:
        vm(std::vector<u64> program);
        void fetch();
        void decode();
        void execute();
        void run();
        ~vm();
    };
        
}

#endif // VM_HPP