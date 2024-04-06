#ifndef TASK_3_H
#define TASK_3_H

#include <stdio.h>

// We will assume that the strings read by the Tokenizer
// can be processed as an array of maximum 20 Tokens.
#define MAX_TOKENS 20
// We will assume that the numbers in strings read by the Tokenizer
// consist of maximum 20 digits.
#define MAX_DIGITS 20

// Struct for CFG symbols.
typedef struct {
    char symbol;
    int is_terminal;
    int is_start; 
} CFGSymbol;

// Function to initialize a CFGSymbol.
void init_CFGSymbol(CFGSymbol* symbol, char text, int is_terminal, int is_start);

// Specific initializer for a terminal symbol.
void init_Terminal(CFGSymbol* symbol, char text);

// Tokenizer function.
void tokenizeString(char* str, CFGSymbol* symbols, int* symbol_count, CFGSymbol* plus, CFGSymbol* n);

#endif  // TOKENIZER_H
