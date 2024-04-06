// Only using stdio, no string library needed for this.
#include <stdio.h>
// Define the maximum number of symbols on the RHS of a rule a 10 (should be enough).
#include "Task4.h"

// Generic function to initialize a CFGSymbol.
void init_CFGSymbol(CFGSymbol* symbol, char text, int is_terminal, int is_start) {
    symbol->symbol = text;
    symbol->is_terminal = is_terminal;
    symbol->is_start = is_start;
}


// Specific initializers for different types of symbols (non-terminal symbol).
void init_NonTerminal(CFGSymbol* symbol, char text) {
    init_CFGSymbol(symbol, text, 0, 0);
}


// Specific initializers for different types of symbols (terminal symbol).
void init_Terminal(CFGSymbol* symbol, char text) {
    init_CFGSymbol(symbol, text, 1, 0);
}


// Specific initializers for different types of symbols (start symbol).
void init_StartSymbol(CFGSymbol* symbol, char text) {
    init_CFGSymbol(symbol, text, 0, 1);
}


// Function to create a production rule.
// - It should check if lhs is a non-terminal symbol.
// It will display an error message and set the rhs_length attribute to -1 otherwise.
// - It will then assign the sequence of symbols in CFGSymbol rhs[]
// to the production rule rhs attribute, and in the process, define the number of elements rhs_length.
CFGProductionRule createProductionRule(CFGSymbol lhs, CFGSymbol rhs[], int rhs_length) {
    CFGProductionRule rule;
    rule.lhs = lhs;
    if (lhs.is_terminal) {
        printf("Invalid production rule, lhs is a terminal symbol.\n");
        rule.rhs_length = -1;
        return rule;
    }
    for (int i = 0; i < rhs_length; ++i) {
        rule.rhs[i] = rhs[i];
    }
    rule.rhs_length = rhs_length;
    return rule;
}


// Function to print a production rule.
// - Can safely assumes that we will have a valid production rule already.
// - Print the left-hand side symbol, then print " --> ",
// and finally iterate through the right-hand side symbols and print them.
void printProductionRule(CFGProductionRule rule) {
    printf("%c --> ", rule.lhs.symbol);
    for (int i = 0; i < rule.rhs_length; ++i) {
        printf("%c", rule.rhs[i].symbol);
    }
    printf("\n");
}


// Function to create a CFG.
// - Receives a CFG struct, an array of symbols, an array of production rules and counters for the lengths of these arrays.
// - Should simply assign each of these arrays and int values to the appropriate attributes of the CFG struct.
void init_CFG(CFG* cfg, CFGSymbol symbols[], int symbol_count, CFGSymbol startSymbol, CFGProductionRule rules[], int rule_count) {
    for (int i = 0; i < symbol_count; ++i) {
        cfg->symbols[i] = symbols[i];
    }
    cfg->startSymbol = startSymbol;
    for (int i = 0; i < rule_count; ++i) {
        cfg->rules[i] = rules[i];
    }
    cfg->symbol_count = symbol_count;
    cfg->rule_count = rule_count;
}

// Function for printing the CFG as expected.
// - Should display all the production rules in the format "(k) lhs --> rhs".
void printCFG(const CFG cfg) {
    for (int i = 0; i < cfg.rule_count; ++i) {
        printf("(%d) %c --> ", i + 1, cfg.rules[i].lhs.symbol);
        for (int j = 0; j < cfg.rules[i].rhs_length; ++j) {
            printf("%c", cfg.rules[i].rhs[j].symbol);
        }
        printf("\n");
    }
}


// A simple tokenizer function.
// Behaves as explained in instructions.
void tokenizeString(char* str, CFGSymbol* symbols, int* symbol_count, CFGSymbol* plus, CFGSymbol* n) {
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


// This function will start the derivation by assigning a single CFGSymbol (the start symbol of our CFG)
// in the array derivation and will update the derivation length in the process.
void startDerivation(CFGSymbol* derivation, int* derivation_length, CFG* cfg) {
    // Assign the start symbol of the CFG to the first position of the derivation array.
    derivation[0] = cfg->startSymbol;
    // Update the derivation length.
    *derivation_length = 1;
}


// This function will retrieve the production rule, located in the array of Production rules of our CFG at index ruleIndex.
// It will then apply in on the symbol currently located at position position in the array of CFGSymbols derivation.
// It should perform all the needed checks (symbol in position corresponds to the lhs of production rule,
// will not break maximal length for sequence of tokens, etc.)
// Eventually, will update the derivation and derivation_length variables, accordingly.
// Or do nothing, simply printing an error message if invalid.
void applyProductionRule(CFGSymbol* derivation, int* derivation_length, CFG* cfg, int ruleIndex, int position) {
    if (ruleIndex < 1 || ruleIndex > cfg->rule_count) {
        printf("Invalid rule index.\n");
        return;
    }
    CFGProductionRule rule = cfg->rules[ruleIndex - 1];
    if (position < 0 || position >= *derivation_length || derivation[position].symbol != rule.lhs.symbol) {
        printf("Rule cannot be applied at the given position.\n");
        return;
    }
    int new_length = *derivation_length + rule.rhs_length - 1;
    if (new_length > MAX_SYMBOLS) {
        printf("Applying the rule exceeds the maximum derivation length.\n");
        return;
    }
    for (int i = *derivation_length - 1; i > position; --i) {
        derivation[i + rule.rhs_length - 1] = derivation[i];
    }
    for (int i = 0; i < rule.rhs_length; ++i) {
        derivation[position + i] = rule.rhs[i];
    }
    *derivation_length = new_length;
}


// Function to check if we have a match in the derivation.
int checkDerivation(CFGSymbol* derivation, int derivation_length, CFGSymbol* tokens, int token_count) {
    // If derivation and tokens do not have the same number of symbols,
	// no chance that there is a match.
	if (derivation_length != token_count) {
        printf("Derivation unsuccessful: Length mismatch, stopping early.\n");
        return 0;
    }
	
	// Otherwise, check all symbols one by one.
	// Stop early if two symbols do not match and return 0 (False).
    for (int i = 0; i < derivation_length; ++i) {
        if (derivation[i].symbol != tokens[i].symbol) {
            printf("Derivation unsuccessful: Symbol mismatch at position %d.\n", i);
            return 0;
        }
    }
	
	// Otherwise, return 1 (True).
    printf("Derivation successful!\n");
    return 1;
}


// Helper function for printing arrays of CFG symbols
void printArraySymbols(CFGSymbol* symbols, int count) {
    for (int i = 0; i < count; ++i) {
        printf("Token(%c) ", symbols[i].symbol);
    }
    printf("\n");
}


// Some test cases
int main(void) {
    CFGSymbol S, E, T, plus, n;
	CFGSymbol rhs0[1], rhs1[1], rhs2[3], rhs3[1], rhs4[1];
	CFGProductionRule rule0, rule1, rule2, rule3, rule4;
	CFG cfg;
	CFGSymbol symbols[5];
	CFGProductionRule rules[4];
	CFGSymbol token_symbols[MAX_TOKENS];
    int token_count = 0;
    char str[] = "17+4+526";
	CFGSymbol derivation1[MAX_TOKENS];
    int derivation1_count = 0;
	CFGSymbol derivation2[MAX_TOKENS];
    int derivation2_count = 0;

    // Initialize CFGsymbols.
    init_StartSymbol(&S, 'S');
    init_NonTerminal(&E, 'E');
    init_NonTerminal(&T, 'T');
    init_Terminal(&plus, '+');
    init_Terminal(&n, 'n');
	
	// Define the production rules.
    rhs1[0] = E;
    rule1 = createProductionRule(S, rhs1, 1);
    rhs2[0] = E; 
    rhs2[1] = plus;
    rhs2[2] = T;
    rule2 = createProductionRule(E, rhs2, 3);
    rhs3[0] = T;
    rule3 = createProductionRule(E, rhs3, 1);
    rhs4[0] = n;
    rule4 = createProductionRule(T, rhs4, 1);
	
    // Initialize the CFG.
    symbols[0] = S;
    symbols[1] = E;
    symbols[2] = T;
    symbols[3] = plus;
    symbols[4] = n;
    rules[0] = rule1;
    rules[1] = rule2;
    rules[2] = rule3;
    rules[3] = rule4;
    int symbol_count = sizeof(symbols)/sizeof(symbols[0]);
    int rule_count = sizeof(rules)/sizeof(rules[0]);
    init_CFG(&cfg, symbols, symbol_count, S, rules, rule_count);

    // Tokenize the string
    tokenizeString(str, token_symbols, &token_count, &plus, &n);
	
	// Test case #1 for string
	// A Derivation Sequence that is valid.
    printf("--- Test case 1\n");
    startDerivation(derivation1, &derivation1_count, &cfg);
    printArraySymbols(derivation1, derivation1_count);
	applyProductionRule(derivation1, &derivation1_count, &cfg, 1, 0);
	printArraySymbols(derivation1, derivation1_count);
	applyProductionRule(derivation1, &derivation1_count, &cfg, 2, 0);
	printArraySymbols(derivation1, derivation1_count);
	applyProductionRule(derivation1, &derivation1_count, &cfg, 2, 0);
	printArraySymbols(derivation1, derivation1_count);
	applyProductionRule(derivation1, &derivation1_count, &cfg, 3, 0);
	printArraySymbols(derivation1, derivation1_count);
	applyProductionRule(derivation1, &derivation1_count, &cfg, 4, 0);
	printArraySymbols(derivation1, derivation1_count);
	applyProductionRule(derivation1, &derivation1_count, &cfg, 4, 2);
	printArraySymbols(derivation1, derivation1_count);
	applyProductionRule(derivation1, &derivation1_count, &cfg, 4, 4);
	printArraySymbols(derivation1, derivation1_count);
	checkDerivation(derivation1, derivation1_count, token_symbols, token_count);
	printf("\n");

    // Test case #2 for string
	// A Derivation Sequence that is invalid.
    printf("--- Test case 2\n");
    startDerivation(derivation2, &derivation2_count, &cfg);
    printArraySymbols(derivation2, derivation2_count);
    applyProductionRule(derivation2, &derivation2_count, &cfg, 2, 0);
	printArraySymbols(derivation2, derivation2_count);
	applyProductionRule(derivation2, &derivation2_count, &cfg, 1, 1);
	printArraySymbols(derivation2, derivation2_count);
	applyProductionRule(derivation2, &derivation2_count, &cfg, 1, 0);
	printArraySymbols(derivation2, derivation2_count);
	applyProductionRule(derivation2, &derivation2_count, &cfg, 2, 0);
	printArraySymbols(derivation2, derivation2_count);
	applyProductionRule(derivation2, &derivation2_count, &cfg, 2, 0);
	printArraySymbols(derivation2, derivation2_count);
	applyProductionRule(derivation2, &derivation2_count, &cfg, 3, 0);
	printArraySymbols(derivation2, derivation2_count);
	applyProductionRule(derivation2, &derivation2_count, &cfg, 4, 0);
	printArraySymbols(derivation2, derivation2_count);
	applyProductionRule(derivation2, &derivation2_count, &cfg, 4, 2);
	printArraySymbols(derivation2, derivation2_count);
	applyProductionRule(derivation2, &derivation2_count, &cfg, 4, 4);
	printArraySymbols(derivation2, derivation2_count);
    derivation2[0] = plus;
	printArraySymbols(derivation2, derivation2_count);
	checkDerivation(derivation2, derivation2_count, token_symbols, token_count);

    return 0;
}