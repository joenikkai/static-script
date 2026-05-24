#ifndef VM_HPP

#define VM_HPP


#include <cstdint>
#include <vector>

#include "../include/instructions.hpp"

namespace vm
{
    class vm
    {
    private:
        std::vector<uint64_t> program;
        volatile bool running;

    public:
        vm(std::vector<uint64_t> program);
        virtual void fetch() = 0;
        virtual void decode() = 0;
        virtual void execute() = 0;
        virtual void run() = 0;
        inline uint64_t get_word(uint64_t index)
        {
            return this->program[index];
        }
        inline void stop()
        {
            this->running = false;
        }
        inline bool isrunning()
        {
            return this->running;
        }
        uint8_t get_type(uint64_t word);
        uint64_t get_data(uint64_t word);
        virtual ~vm();
    };

    class stack_vm : public vm
    {
    private:
        uint8_t type = 0;
        uint64_t data = 0;
        uint64_t bp = 0; // base pointer
        uint64_t sp = 0; // stack pointer
        uint64_t pc = 0; // program counter

        std::vector<uint64_t> stack;
        std::vector<uint64_t> call_stack;
        std::vector<uint64_t> heap_addresses;

    public:
        stack_vm(std::vector<uint64_t> program);
        void fetch() override;
        void decode() override;
        void execute() override;
        void run() override;
        ~stack_vm();
    };

    class register_vm : public vm
    {
    private:
        std::vector<uint64_t> registers;
        std::vector<uint64_t> call_register;
        std::vector<uint64_t> heap_addresses;

    public:
        register_vm(std::vector<uint64_t> program);
        void fetch() override;
        void decode() override;
        void execute() override;
        void run() override;
        ~register_vm();
    };

}

#endif // VM_HPP