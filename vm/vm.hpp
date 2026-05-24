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
        virtual void fetch() = 0;
        virtual void decode() = 0;
        virtual void execute() = 0;
        virtual void run() = 0;
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
        stack_vm(std::vector<u64> program);
        void fetch();
        void decode();
        void execute();
        void run();
        ~stack_vm();
    };

    class register_vm : vm
    {
    private:
        std::vector<u64> registers;
        std::vector<u64> call_register;
        std::vector<u64> heap_addresses;

    public:
        register_vm(std::vector<u64> program);
        void fetch();
        void decode();
        void execute();
        void run();
        ~register_vm();
    };

}

#endif // VM_HPP