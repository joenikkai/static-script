#ifndef VM_HPP

#define VM_HPP


#include <cstdint>
#include <vector>

#include "../include/instructions.hpp"

namespace vm
{
    struct op_code_type1
    {
        uint8_t type;
        uint64_t data;
    };

    class vm
    {
    private:
        std::vector<uint64_t> program;
        volatile bool running;

    public:
        vm(std::vector<uint64_t> program);
        virtual uint64_t fetch() = 0;
        virtual void decode() = 0;
        virtual void execute() = 0;
        virtual void run() = 0;
        inline uint64_t get_word(uint64_t index) // Check if vm is still executing
        {
            return this->program[index];
        }
        inline void stop() // Stop execution
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
        struct op_code_type1 opcode; /* currently executing opcode */
        uint64_t bp = 0; /* base pointer */
        uint64_t sp = 0; /* stack pointer */
        uint64_t pc = 0; /* program counter */

        std::vector<struct op_code_type1> stack;
        std::vector<struct op_code_type1> call_stack;
        std::vector<struct op_code_type1> heap_addresses;

    public:
        stack_vm(std::vector<uint64_t> program);
        uint64_t fetch() override;
        void decode() override;
        void execute() override;
        void run() override;
        void push(uint64_t word);
        uint64_t pop();
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
        uint64_t fetch() override;
        void decode() override;
        void execute() override;
        void run() override;
        ~register_vm();
    };

}

#endif // VM_HPP