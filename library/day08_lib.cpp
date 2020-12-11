#include "day08_lib.h"
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace day08lib;


namespace {

typedef enum {
    HALT
    ,NOP
    ,ACC
    ,JMP
} Opcode;

typedef struct Instruction
{
    Instruction() :
        opcode(Opcode::HALT)
    {}

    std::string src;
    Opcode opcode;
    int param;

    void compile()
    {
        if (src == "nop")
        {
            opcode = Opcode::NOP;
        }
        else if ( src == "acc" )
        {
            opcode = Opcode::ACC;
        }
        else if (src == "jmp")
        {
            opcode = Opcode::JMP;
        }
        else 
        {
            opcode = Opcode::HALT;
        }
    }
} Instruction;

typedef enum 
{
    initializing,
    running,
    blocking,
    halted,
    exception
} Status;

typedef std::vector<Instruction> Program;

typedef struct ProgramContext 
{
    ProgramContext(const Program& prog)
        : status(Status::initializing),
          PC(0), 
          ACC(0), 
          PRIOR_ACC(0), 
          program(prog)
    {}

    Status status;
    std::size_t PC;
    std::size_t ACC;
    std::size_t PRIOR_ACC;
    typedef std::map<std::size_t, std::size_t> ProfileType;
    ProfileType profile;


    const Program program;

    void step()
    {
        PRIOR_ACC = ACC;

        if (PC >= program.size())
        {
            status = Status::exception;
            return;
        }

        status = Status::running;
        update_profile();
        switch (program[PC].opcode)
        {
            case Opcode::ACC:
            {
                ACC += program[PC].param;
                ++PC;
            }
            break;

            case Opcode::JMP:
            {
                PC += program[PC].param;
            }
            break;

            case Opcode::NOP:
            {
                ++PC;
            }
            break;

            default:
            {
                status = Status::exception;
                return;
            }
            break;
        }

    }

    void update_profile()
    {
        size_t steps(1);
        auto p = profile.find(PC);
        if ( p!= profile.end())
        {
            steps = p->second;
            ++steps;
        }
        profile.insert_or_assign( PC, steps);
    }

    bool repeated_an_instruction()
    {
        return profile.end() != std::find_if(profile.begin(), profile.end(), [](ProfileType::value_type p){ return p.second > 1;});
    }

} ProgramContext;

Instruction parse_line(const std::string src_line)
{
    Instruction instruction;

    std::istringstream asm_line(src_line);

    asm_line >> std::setw(3) >> instruction.src
             >> instruction.param
             ;

    instruction.compile();

    return instruction;
}


Program parse_datastream(std::istream& data_stream)
{
    Program program;

    std::string line;
    for (;std::getline(data_stream, line);)
    {
        auto instruction = parse_line(line);
        program.push_back(instruction);
    }
    
    return program;
}


std::pair<int, Status> run_until_repeat_instruction(const Program program)
{
    ProgramContext context(program);
    for(;;)
    {
        context.step();
        if ( context.repeated_an_instruction() || context.status == Status::exception)
        {
            return std::make_pair(context.PRIOR_ACC, context.status);
        }
    }
}

std::pair<int, Status> patch_until_no_infinite_loop(Program program)
{
    for ( std::size_t pc = 0; pc < program.size(); ++pc)
    {
        auto saved_instruction = program[pc];
        if ( saved_instruction.opcode != Opcode::ACC )
        {
            if (saved_instruction.opcode == Opcode::NOP)
            {
                program[pc].opcode = Opcode::JMP;
            }
            else if (saved_instruction.opcode == Opcode::JMP)
            {
                program[pc].opcode = Opcode::NOP;
            }

            auto acc = run_until_repeat_instruction(program);
            if (acc.second == Status::exception)
            {
                return acc;
            }

            program[pc].opcode = saved_instruction.opcode;
        }
    }

    return std::make_pair(0, Status::halted);
}


}



std::size_t day08lib::part1_solve(std::istream& data_stream)
{
    auto program = parse_datastream(data_stream);
    auto accumulator = run_until_repeat_instruction(program);
    return accumulator.first;
}

std::size_t day08lib::part2_solve(std::istream& data_stream)
{
    auto program = parse_datastream(data_stream);
    auto accumulator = patch_until_no_infinite_loop(program);
    return accumulator.first;
}
