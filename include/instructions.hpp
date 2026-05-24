#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP
#include <cstdint>

/**
 * we are going to encode data type in the first 4 bits therefore the maximum value allowed is 1.152921505×10¹⁸
 * 0 Instruction
 * 1 address/pointer
 * 2 int
 * 3 float
 * 4 bool
 * 5 char
 *
 * You might ask the last (16-4)=12 values for. They are for future adjustments
 * 
 * ----
 * ----
 * +-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
 * |       0     |      1      |      2      |       3     |       4     |      5      |      6      |      7      |
 * +-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
 * | 00 00 00 02 | 00 00 00 00 | 00 00 00 00 | 00 00 00 00 | 00 00 00 00 | 00 00 00 00 | 00 00 00 00 | 00 00 00 0f |
 * +-^---------^-+-^-----------+-------------+-------------+-------------+-------------+-------------+-----------^-+
 *   |         |   |                                                                                             |
 *   +-+-------+   +-------------------------------------------------------+-------------------------------------+
 *     |                                                                   |
 *     This is where the datatype is stored.                               This range is where data is stored
 * - Therefore the type of this data is an integer
 * - and the value of this value is 15
 *
 */

enum types : uint8_t
{
    INSTRUCTIONS = 0x0,
    ADDRESS,
    INTEGER,
    FLOAT,
    BOOLEAN,
    CHARACTER,
    TYPE_COUNT
};

enum instructions : uint64_t
{
    HALT = 0x0,
    PUSH, /* Push to the stack */
    POP,  /* Pop from the stack */

    PUSH_BP, /* Push current base pointer */
    POP_BP, /* Revert to previous base pointer */

    MOV_BP_SP, /* Move base pointer to stack pointer */
    MOV_SP_BP, /* Move stack pointer to base pointer */

    SWAP, 
    CALL, /* used to call a function */
    RET,  /* return a value from a function call */

    LOAD,  /* Read from a variable */
    STORE, /* Store to a variable  */
    WRITE, /* Print */
    DP,    /* Duplicate */

    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,

    JMP, /* Jump */
    JZ,  /* Jump if zero */
    JNZ, /* Jump if not zero */

    CMP_EQ,  /* compare if equal */
    CMP_NEQ, /* compare not equal to */

    CMP_GT, /* compare if greater than */
    CMP_LT, /* compareif less than */

    CMP_GT_EQ, /* compare greater than or equals to  */
    CMP_LT_EQ, /* compare less than or equal to  */

    INSTRUCTIONS_COUNT /* Number of instructions */
};
#endif /* INSTRUCTIONS_HPP */