/*
- Write Program evaluation function
- Write memory management part.
*/


#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define ARENA_IMPLEMENTATION
#include "arena.h"

#define MAX_TAPE_SIZE 1024

typedef struct Program Program;

typedef enum {
    ZERO, // DO NOTHING, MOVE INS HEAD RIGHT, IF READ is also zero, MOVE INS back to START
    MOV_WRITE_LEFT, // Move Write HEAD Left, WRITE current READ
    MOV_WRITE_RIGHT, // Move Write HEAD Right, WRITE current READ
    MOV_READ_LEFT, // Move READ head left
    MOV_READ_RIGHT, // Move READ head right
    WRITE, // Write current READ
    SWAP, // Swap INS head and READ head
    START, // Program start: WRITE start to tape, Move Read HEAD RIGHT, Move Write HEAD RIGHT, 
    END, // Program end: WRITE stop to tape.
    
    COUNT
} INS;

static_assert(COUNT == 9, "Amount of instructions have changed");

const char *ins_symbols[COUNT] = {
    [ZERO] = "o",
    [MOV_WRITE_LEFT] = ">",
    [MOV_WRITE_RIGHT] = "<",
    [MOV_READ_LEFT] = "{",
    [MOV_READ_RIGHT] = "}",
    [WRITE] = "^",
    [SWAP] = "%",
    [START] = "s",
    [END] = "e"
};

struct Program {
    char tape[MAX_TAPE_SIZE];
    Program *parent;
    Program *progeny;
    int depth;
    int program_size;
};

int program_size(Program *program) {
    return 0;
}

Program generate_random_program() {
    srand(time(NULL));
    Program program = {0};
    
    program.tape[0] = START;
    for(int i = 1; i < MAX_TAPE_SIZE; i++) {
        program.tape[i] = rand() % COUNT;  // Generates random instructions
        if (program.tape[i] == START) --i;
        if (program.tape[i] == END) break;
    }
    program.program_size = program_size(&program);
    return program;
}

void print_program(Program *program) {
    
    if (program == NULL) return;
    printf("P(%d):", program->program_size);
    
    if (program->tape[0] != START) {
        printf("\n"); 
        return;
    }
    
    for (int i = 0; i < MAX_TAPE_SIZE; i++) {
        unsigned char instruction = program->tape[i];
        
        if (instruction >= COUNT) {
            printf("Invalid instruction found!");
            break;
        }
        
        printf("%s", ins_symbols[instruction]);
        
        if (instruction == END) break;
    }
    printf("\n");
}

Program evaluate_program(Program *program) {

    // TODO CRAFT: write this code
    
    Program new_program = {0};
    new_program.program_size = program_size(&new_program);
    
    return new_program;
}

int main() {
    printf("Hello World!!\n");
    Program random_program = generate_random_program();
    print_program(&random_program);
    Program next_program = evaluate_program(&random_program);
    print_program(&next_program); 
}