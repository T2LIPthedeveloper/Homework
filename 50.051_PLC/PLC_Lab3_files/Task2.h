#ifndef TASK_2_H
#define TASK_2_H

#include <stdio.h>

// Define the maximum number of symbols on the RHS of a rule a 10 (should be enough).
#define MAX_RHS 10
// Define the maximum number of symbols in a CFG as 10 (should be enough).
#define MAX_SYMBOLS 10
// Define the maximum number of rules in a CFG as 10 (should be enough).
#define MAX_RULES 10

// Struct for CFG symbols.
typedef struct {
    char symbol;
    int is_terminal;
    int is_start;
} CFGSymbol;

// Struct for a production rule of our CFG.
typedef struct {
    CFGSymbol lhs;
    CFGSymbol rhs[MAX_RHS];
    int rhs_length;
} CFGProductionRule;

// Struct for the full CFG.
typedef struct {
    CFGSymbol symbols[MAX_SYMBOLS];
    CFGSymbol startSymbol;
    CFGProductionRule rules[MAX_RULES];
    int symbol_count;
    int rule_count;
} CFG;

// Function prototypes
void init_CFGSymbol(CFGSymbol* symbol, char text, int is_terminal, int is_start);
void init_NonTerminal(CFGSymbol* symbol, char text);
void init_Terminal(CFGSymbol* symbol, char text);
void init_StartSymbol(CFGSymbol* symbol, char text);
CFGProductionRule createProductionRule(CFGSymbol lhs, CFGSymbol rhs[], int rhs_length);
void printProductionRule(CFGProductionRule rule);
void init_CFG(CFG* cfg, CFGSymbol symbols[], int symbol_count, CFGSymbol startSymbol, CFGProductionRule rules[], int rule_count);
void printCFG(const CFG cfg);

#endif  // CFG_PARSER_H
