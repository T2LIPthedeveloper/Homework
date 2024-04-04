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
    // CFG for parsing table:
    // E -> number
    // E -> (EOE)
    // O -> +

    // LL1 table
    //  n  +  (  )  $
    // E  0  -1  1  -1 -1
    // O -1  2  -1  -1 -1

    
    // Rule 1: E -> number
    if (currentChar == 'E' && targetChar == 'n') {
        return 0;
    }
    // Rule 2: E -> (EOE)
    if (currentChar == 'E' && targetChar == '(') {
        return 1;
    }
    // Rule 3: O -> +
    if (currentChar == 'O' && targetChar == '+') {
        return 2;
    }

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
    while (*currentString && *cursor) {
		// Look at both strings and fetch
        printf("Current Parsing State: %s, Remaining Target: %s\n", currentString, cursor);
        char currentChar = currentString[0];
        char targetChar = *cursor;
		
		// Scenario 1: we see a terminal in currentChar
        if (isTerminal(currentChar)) {
            if (currentChar == targetChar) {
                printf("Matching terminal '%c'\n", currentChar);
                // Remove the matched terminal from currentString
				memmove(currentString, currentString + 1, strlen(currentString));
				// Advance the cursor if the terminal matches
                cursor++;
            } else {
				// Failure case 1: mismatch on current two terminals
                printf("Error: terminal '%c' does not match target '%c'\n", currentChar, targetChar);
                break;
            }
		// Scenario 2: we see a non-terminal in currentChar
        } else if (isNonTerminal(currentChar)) {
			// Find and apply rule according to our LL1 table and function
            int ruleIndex = selectRule(currentChar, targetChar);
            if (ruleIndex != -1) {
                printf("Applying rule: %s\n", rules[ruleIndex].replacement);
                char* newString = applyProduction(currentString, 0, rules[ruleIndex]);
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
    if (!*currentString && !*cursor) {
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

/*

Question 6: LL1 Table

CFG rules:
0. E -> number
1. E -> (EOE)
2. O -> +

LL1 Table:

E -> number: n
E -> (EOE): (
O -> +: +
    
      n  +  (  )  $
E     0  -1 1  -1 -1
O    -1  2 -1  -1 -1

With the numbers corresponding to the rules.
*/