#include <stdio.h>

/* Define New Enum for Combined FSM */
typedef enum {
    ???
} CombinedState;

/* Define Combined FSM Struct, as in previous tasks.  */
typedef struct {
    ???
} CombinedFSM;

/* 
    Initialize the Combined FSM, as in previous tasks.
    - For simplicity, we will not be storing letters ('a', 'b', 'c' and 'd') in attributes.
*/
void initCombinedFSM(CombinedFSM *combinedFsm) {
    ???
}

/* Process given input_char for the Combined FSM.  */
void processCharCombined(CombinedFSM *combinedFsm, char input_char) {
    ???
}

/* 
    Running the Combined FSM, as in previous tasks.
    - Simple for loop on all characters as before.
    - Break for loop early on rejection, if you want.
    - Return true if the FSM is in correct accepting state.
 */
int runRegexCombined(CombinedFSM *combinedFsm, const char *str) {
    ???
}

int main() {
	
	/* Initialize our FSM object. */
    CombinedFSM combinedFsm;
	
	/* Some test strings, including the empty string.  */
    char *testStrings[] = {"a", "abd", "acd", "aad", "abdd", "ac", "abcd", "abda", NULL};
	int i;
    int matches;
	/* Run test cases and reset FSM each time. */
    for (i = 0; testStrings[i] != NULL; i++) {
		initCombinedFSM(&combinedFsm);
        matches = runRegexCombined(&combinedFsm, testStrings[i]);
        printf("String \"%s\" matches: %s\n", testStrings[i], matches ? "Yes" : "No");
    }
    return 0;
}
