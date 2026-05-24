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
        virtual void fetch();
        virtual void decode();
        virtual void execute();
        virtual void run();
        uint8_t get_type(uint64_t word);
        uint64_t get_data(uint64_t word);
        virtual ~vm();
    };

    class stack_vm : vm
    {
    private:
        std::vector<u64> stack;
        std::vector<u64> call_stack;
        std::vector<u64> heap_addresses;

    public:
        void fetch();
        void decode();
        void execute();
        void run();
    };
}

#endif // VM_HPP