// Only using stdio, no string library needed for this.
#include <stdio.h>

#include "Task3.h"

// Generic function to initialize a CFGSymbol.
void init_CFGSymbol(CFGSymbol* symbol, char text, int is_terminal, int is_start) {
    symbol->symbol = text;
    symbol->is_terminal = is_terminal;
    symbol->is_start = is_start;
}


// Specific initializers for different types of symbols (terminal symbol).
void init_Terminal(CFGSymbol* symbol, char text) {
    init_CFGSymbol(symbol, text, 1, 0);
}


// A simple tokenizer function.
// Behaves as explained in instructions.
void tokenizeString(char* str, CFGSymbol* symbols, int* symbol_count, CFGSymbol* plus, CFGSymbol* n) {
    // Initialize indexing and symbol count.
	int i = 0;
    *symbol_count = 0;
    while (str[i] != '\0' && *symbol_count < MAX_TOKENS) {
        if (str[i] == plus->symbol) {
            symbols[*symbol_count] = *plus;
            *symbol_count += 1;
            i += 1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            int start = i;
            while (str[i] >= '0' && str[i] <= '9' && i - start < MAX_DIGITS) {
                i += 1;
            }
            symbols[*symbol_count] = *n;
            *symbol_count += 1;
        } else {
            i += 1;
        }
    }
}


// Some test cases
int main(void) {
    CFGSymbol plus, n;
    CFGSymbol symbols1[MAX_TOKENS], symbols2[MAX_TOKENS];
    int symbol_count1 = 0;
    int symbol_count2 = 0;
    char str1[] = "17+4+526";
    char str2[] = "74++26+";

    // Initialize terminal symbols for Tokenizer.
    init_Terminal(&plus, '+');
    init_Terminal(&n, 'n');

    // Test case #1 for Tokenizer
    tokenizeString(str1, symbols1, &symbol_count1, &plus, &n);
    printf("--- Test case 1\nString: %s\nTokens: ", str1);
    for (int i = 0; i < symbol_count1; ++i) {
        printf("Token(%c) ", symbols1[i].symbol);
    }
    printf("\n");

    // Test case #2 for Tokenizer
    tokenizeString(str2, symbols2, &symbol_count2, &plus, &n);
    printf("--- Test case 2\nString: %s\nTokens: ", str2);
    for (int i = 0; i < symbol_count2; ++i) {
        printf("Token(%c) ", symbols2[i].symbol);
    }
    printf("\n");

    return 0;
}