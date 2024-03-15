#include <stdio.h>

/* Regex = "^a(b|c)d*$" */
/* Define New Enum for Combined FSM */
typedef enum {
    INITIAL_STATE_COMBINED,
    ACCEPTING_STATE_COMBINED
} CombinedState;

/* Define Combined FSM Struct, as in previous tasks.  */
typedef struct {
    CombinedState currentState;
    char firstLetter;
    char secondLetter;
    char thirdLetter;
} CombinedFSM;

/* 
    Initialize the Combined FSM, as in previous tasks.
    - For simplicity, we will not be storing letters ('a', 'b', 'c' and 'd') in attributes.
*/
void initCombinedFSM(CombinedFSM *combinedFsm) {
    combinedFsm->currentState = INITIAL_STATE_COMBINED;
}

/* Process given input_char for the Combined FSM.  */
void processCharCombined(CombinedFSM *combinedFsm, char input_char) {
    switch (combinedFsm->currentState) {
        case INITIAL_STATE_COMBINED:
            if (input_char == 'a' && combinedFsm->currentState == INITIAL_STATE_COMBINED) {
                combinedFsm->currentState = INITIAL_STATE_COMBINED;
            } else if (input_char == 'b' && combinedFsm->currentState == INITIAL_STATE_COMBINED) {
                combinedFsm->currentState = ACCEPTING_STATE_COMBINED;
            } else if (input_char == 'c' && combinedFsm->currentState == INITIAL_STATE_COMBINED) {
                combinedFsm->currentState = ACCEPTING_STATE_COMBINED;
            } else if (input_char == 'd' && combinedFsm->currentState == ACCEPTING_STATE_COMBINED) {
                combinedFsm->currentState = ACCEPTING_STATE_COMBINED;
            } else {
                combinedFsm->currentState = INITIAL_STATE_COMBINED;
            }
            break;
        case ACCEPTING_STATE_COMBINED:
            if (input_char == 'd') {
                combinedFsm->currentState = ACCEPTING_STATE_COMBINED;
            } else {
                combinedFsm->currentState = INITIAL_STATE_COMBINED;
            }
            break;
    }
}

/* 
    Running the Combined FSM, as in previous tasks.
    - Simple for loop on all characters as before.
    - Break for loop early on rejection, if you want.
    - Return true if the FSM is in correct accepting state.
 */
int runRegexCombined(CombinedFSM *combinedFsm, const char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        processCharCombined(combinedFsm, str[i]);
    }
    return combinedFsm->currentState == ACCEPTING_STATE_COMBINED;
}

int main() {
	
	/* Initialize our FSM object. */
    CombinedFSM combinedFsm;
	
	/* Some test strings, including the empty string.  */
    char *testStrings[] = {"a", "abd", "acd", "aad", "abdd", "ac", "abcd", "abda", "bcd", NULL};
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
