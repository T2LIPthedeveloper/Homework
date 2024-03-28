// Only using stdio, no string library needed for this.
#include <stdio.h>
// Define the maximum number of symbols on the RHS of a rule a 10 (should be enough).
#define MAX_RHS 10
// Define the maximum number of symbols in a CFG as 10 (should be enough).
#define MAX_SYMBOLS 10
// Define the maximum number of rules in a CFG as 10 (should be enough).
#define MAX_RULES 10
// We will assume that the strings read by the Tokenizer
// can be processed as an array of maximum 20 Tokens.
#define MAX_TOKENS 20
// We will assume that the numbers in strings read by the Tokenizer
// consist of maximum 20 digits.
#define MAX_DIGITS 20


// Struct for CFG symbols.
// - symbol: A single character containing the representation of the CFG symbol.
// - is_terminal: An int, which indicates whether the symbol is terminal (0 = false, 1 = true)
// - is_start: An int, which indicates whether the symbol is a start symbol (0 = false, 1 = true)
typedef struct {
???
} CFGSymbol;

// Struct for a production rule of our CFG.
// - lhs: The left-hand side of the production rule, which consists of a single non-terminal CFGSymbol.
// - rhs: The right-hand side of the production rule, which consists of a sequence of CFGSymbols,
// defined as an array CFGSymbol elements, with size MAX_RHS.
// - rhs_count: An int denoting the number of symbols in the right-hand side array.
typedef struct {
???
} CFGProductionRule;


// Struct for the full CFG.
// - symbols: An array of possible symbols, defined as an array of CFGSymbol, with size MAX_SYMBOLS.
// - startSymbol: The start symbol of the CFG, as a single CFGSymbol.
// - rules: An array of possible production rules, defined as an array of CFGProductionRule, with size MAX_RULES.
// - symbol_count: An int, denoting the number of CFGSymbol elements in the symbols array.
// - rule_count: An int, denoting the number of CFGProductionRule elements in the rules array.
typedef struct {
???
} CFG;


// Generic function to initialize a CFGSymbol.
void init_CFGSymbol(CFGSymbol* symbol, char text, int is_terminal, int is_start) {
???
}


// Specific initializers for different types of symbols (non-terminal symbol).
void init_NonTerminal(CFGSymbol* symbol, char text) {
???
}


// Specific initializers for different types of symbols (terminal symbol).
void init_Terminal(CFGSymbol* symbol, char text) {
???
}


// Specific initializers for different types of symbols (start symbol).
void init_StartSymbol(CFGSymbol* symbol, char text) {
???
}


// Function to create a production rule.
// - It should check if lhs is a non-terminal symbol.
// It will display an error message and set the rhs_length attribute to -1 otherwise.
// - It will then assign the sequence of symbols in CFGSymbol rhs[]
// to the production rule rhs attribute, and in the process, define the number of elements rhs_length.
CFGProductionRule createProductionRule(CFGSymbol lhs, CFGSymbol rhs[], int rhs_length) {
    ???
}


// Function to print a production rule.
// - Can safely assumes that we will have a valid production rule already.
// - Print the left-hand side symbol, then print " --> ",
// and finally iterate through the right-hand side symbols and print them.
void printProductionRule(CFGProductionRule rule) {
    ???
}


// Function to create a CFG.
// - Receives a CFG struct, an array of symbols, an array of production rules and counters for the lengths of these arrays.
// - Should simply assign each of these arrays and int values to the appropriate attributes of the CFG struct.
void init_CFG(CFG* cfg, CFGSymbol symbols[], int symbol_count, CFGSymbol startSymbol, CFGProductionRule rules[], int rule_count) {
    ???
}

// Function for printing the CFG as expected.
// - Should display all the production rules in the format "(k) lhs --> rhs".
void printCFG(const CFG cfg) {
    ???
}


// A simple tokenizer function.
// Behaves as explained in instructions.
void tokenizeString(char* str, CFGSymbol* symbols, int* symbol_count, CFGSymbol* plus, CFGSymbol* n) {
    ???
}


// This function will start the derivation by assigning a single CFGSymbol (the start symbol of our CFG)
// in the array derivation and will update the derivation length in the process.
void startDerivation(CFGSymbol* derivation, int* derivation_length, CFG* cfg) {
    ???
}


// This function will retrieve the production rule, located in the array of Production rules of our CFG at index ruleIndex.
// It will then apply in on the symbol currently located at position position in the array of CFGSymbols derivation.
// It should perform all the needed checks (symbol in position corresponds to the lhs of production rule,
// will not break maximal length for sequence of tokens, etc.)
// Eventually, will update the derivation and derivation_length variables, accordingly.
// Or do nothing, simply printing an error message if invalid.
void applyProductionRule(CFGSymbol* derivation, int* derivation_length, CFG* cfg, int ruleIndex, int position) {
    // Validate the ruleIndex, checking that it corresponds to a production rule in the CFG.
	// (Remember that our indexing system for production rules starts at 1).
    if (???) {
        printf("Invalid rule index.\n");
        return;
    }
	
	// Retrieve production rule with index ruleIndex.
	// (Remember that our indexing system for production rules starts at 1).
    CFGProductionRule rule = ???;

    // Check if the position is valid for current derivation array.
	// Also check if the symbol at the position matches the lhs of the production rule.
    if (???) {
        printf("Rule cannot be applied at the given position.\n");
        return;
    }

    // Calculate the new length of the derivation to check if it exceeds the limits.
    // COuld simply subtract 1 because we replace 1 symbol in lhs, always.
    int new_length = ???
    if (new_length > MAX_SYMBOLS) {
        printf("Applying the rule exceeds the maximum derivation length.\n");
        return;
    }

    // Shift existing elements to make space for the new symbols from the rule's RHS.
    // (Probably a good idea to start from the end to avoid overwriting elements that need to be shifted)
    for (???) {
        ???
    }

    // Insert the RHS symbols of the rule at the specified position.
    for (???) {
        ???
    }

    // Update the derivation length.
    *derivation_length = new_length;
}


// Function to check if we have a match in the derivation.
int checkDerivation(CFGSymbol* derivation, int derivation_length, CFGSymbol* tokens, int token_count) {
    // If derivation and tokens do not have the same number of symbols,
	// no chance that there is a match.
	if (???) {
        printf("Derivation unsuccessful: Length mismatch, stopping early.\n");
        return 0;
    }
	
	// Otherwise, check all symbols one by one.
	// Stop early if two symbols do not match and return 0 (False).
    for (???) {
        if (???) {
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