#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Same as before
typedef struct{
    char nonTerminal;
    char* replacement;
} ProductionRule;


// Same as before
char* applyProduction(char* currentString, int position, ProductionRule rule) {
    if (position < 0 || position >= strlen(currentString) || currentString[position] != rule.nonTerminal) {
        return NULL;
    }
    char* newString = (char*)malloc(strlen(currentString) + strlen(rule.replacement) + 1); // Ensure space for null terminator
    strncpy(newString, currentString, position); // Copy up to position
    newString[position] = '\0'; // Null-terminate for strcat
    strcat(newString, rule.replacement); // Append replacement
    strcat(newString, currentString + position + 1); // Append the rest of original string
    return newString;
}


// This function will return an int corresponding to the index of the production rule
// to use if the first character in the currentString is currentChar (a non-terminal),
// and the next terminal symbol to match in the targetString is targetChar (a terminal)
int selectRule(char currentChar, char targetChar){
    ???
    // No rule applicable should return -1 instead of 0, 1 or 2.
    return -1; 
}


// Checks if the given character is a non-terminal
int isNonTerminal(char c) {
    return c == 'E' || c == 'O';
}


// Checks if the given character is a terminal
int isTerminal(char c) {
    return c == 'n' || c == '+' || c =='(' || c == ')';
}


// LL1 Parsing function, same parameters as before.
// - startSymbol: the start symbol for our CFG (here, "E").
// - targetString: the sequence of terminals we are trying to match (e.g. "n+n").
// - rules: our array of production rules for the CFG.
// - numRules: the number of production rules.
void LL1Parse(char* startSymbol, char* targetString, ProductionRule* rules, int numRules) {
    printf("Starting the LL1 parsing\n");

    // Dynamic allocation for currentString to allow modifications
    char* currentString = (char*)malloc(strlen(startSymbol) + 1);
    strcpy(currentString, startSymbol);
	
	// Use targetString directly to check next terminal symbol to match
    char* cursor = targetString; 
	
	// Keep parsing until we reach the end of either string or while loops breaks
    while (???) {
		// Look at both strings and fetch
        printf("Current Parsing State: %s, Remaining Target: %s\n", currentString, cursor);
        char currentChar = currentString[0];
        char targetChar = *cursor;
		
		// Scenario 1: we see a terminal in currentChar
        if (isTerminal(currentChar)) {
            if (currentChar == targetChar) {
                printf("Matching terminal '%c'\n", currentChar);
                // Remove the matched terminal from currentString
				memmove(???);
				// Advance the cursor if the terminal matches
                ??? 
            } else {
				// Failure case 1: mismatch on current two terminals
                printf("Error: terminal '%c' does not match target '%c'\n", currentChar, targetChar);
                break;
            }
		// Scenario 2: we see a non-terminal in currentChar
        } else if (isNonTerminal(currentChar)) {
			// Find and apply rule according to our LL1 table and function
            int ruleIndex = ???;
            if (???) {
                printf("Applying rule: %s\n", rules[ruleIndex].replacement);
                char* newString = applyProduction(???);
                free(currentString);
                currentString = newString;
            } else {
				// Failure case 2: no production rule can match next terminal
                printf("Error: no applicable rule for non-terminal '%c' with target '%c'\n", currentChar, targetChar);
                break;
            }
        }
    }

    // Final state check
	// Success if end of string reached at the same time for both strings
	// Failure case 3: one string is empty but not the other one
    if (???) {
        printf("Parsing succeeded.\n");
    } else {
        printf("Parsing failed. Final State: %s, Remaining Target: %s\n", currentString, cursor);
    }
	
	// Free dynamically allocated memory for currentString
    free(currentString); 
}


int main() {
    ProductionRule rules[] = {
        {'E', "n"},
        {'E', "(EOE)"},
        {'O', "+"}
    };
    int numRules = sizeof(rules) / sizeof(rules[0]);
    
    // Test Case 1 "(n+(n+n))"
    printf("Testing CFG on (n+(n+n))\n");
    LL1Parse("E", "(n+(n+n))", rules, numRules);
    
    // Test Case 2 "(n+n)"
    printf("\nTesting CFG on n+n\n");
    LL1Parse("E", "n+n", rules, numRules);
    
    // Test Case 3 "(n+n)"
    printf("\nTesting CFG on (n+(n)+n)\n");
    LL1Parse("E", "(n+(n)+n)", rules, numRules);

    return 0;
}