#ifndef TASK_4_H
#define TASK_4_H

#include <stdio.h>

#define MAX_RHS 10
#define MAX_SYMBOLS 10
#define MAX_RULES 10
#define MAX_TOKENS 20
#define MAX_DIGITS 20

typedef struct {
    char symbol;
    int is_terminal;
    int is_start;
} CFGSymbol;

typedef struct {
    CFGSymbol lhs;
    CFGSymbol rhs[MAX_RHS];
    int rhs_length;
} CFGProductionRule;

typedef struct {
    CFGSymbol symbols[MAX_SYMBOLS];
    CFGSymbol startSymbol;
    CFGProductionRule rules[MAX_RULES];
    int symbol_count;
    int rule_count;
} CFG;

void init_CFGSymbol(CFGSymbol* symbol, char text, int is_terminal, int is_start);
void init_NonTerminal(CFGSymbol* symbol, char text);
void init_Terminal(CFGSymbol* symbol, char text);
void init_StartSymbol(CFGSymbol* symbol, char text);
CFGProductionRule createProductionRule(CFGSymbol lhs, CFGSymbol rhs[], int rhs_length);
void printProductionRule(CFGProductionRule rule);
void init_CFG(CFG* cfg, CFGSymbol symbols[], int symbol_count, CFGSymbol startSymbol, CFGProductionRule rules[], int rule_count);
void printCFG(const CFG cfg);
void tokenizeString(char* str, CFGSymbol* symbols, int* symbol_count, CFGSymbol* plus, CFGSymbol* n);
void startDerivation(CFGSymbol* derivation, int* derivation_length, CFG* cfg);
void applyProductionRule(CFGSymbol* derivation, int* derivation_length, CFG* cfg, int ruleIndex, int position);
int checkDerivation(CFGSymbol* derivation, int derivation_length, CFGSymbol* tokens, int token_count);
void printArraySymbols(CFGSymbol* symbols, int count);

#endif  // CFG_PARSER_H
