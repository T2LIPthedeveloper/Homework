#include <stdio.h>


/* Define the FSM states, as in Task 2. */
typedef enum {
    INITIAL_STATE,
    ACCEPTING_STATE
} State;

/* Define the FSM states for concatenated RegEx FSM */
typedef enum {
    ???
} ConcatState;

/* Define the FSM struct with an added field for the letter, as in Task 2. */
typedef struct {
    State currentState;
    char targetLetter;
} FSM;

/* 
Define the ConcatFSM struct to handle the two FSM objects for concatenation "ab".
    - currentState: Current state of the ConcatFSM.
    - firstLetter: First letter to search for.
    - secondLetter: Second letter to search for.
*/
typedef struct {
    ConcatState currentState;
    char firstLetter;
    char secondLetter;
} ConcatFSM;

/* Initialize the FSM with the target letter, as in Task 2. */
void initFSM(FSM *fsm, char letter) {
    fsm->currentState = INITIAL_STATE;
    fsm->targetLetter = letter;
}

/* 
    Initialize the ConcatFSM with two FSM objects.
    - Set initial state as ???.
    - Fetch targetLetter attributes from both FSMs and assign correctly to ConcatFSM attributes.
*/
void initConcatFSM(ConcatFSM *concatFsm, FSM *fsm1, FSM *fsm2) {
    concatFsm->currentState = ???;
    concatFsm->firstLetter = ???;
    concatFsm->secondLetter = ???;
}

/* 
    Process a character input for the ConcatFSM.
    - Implements the correct transition logic for our FSM.
*/
void processCharConcat(ConcatFSM *concatFsm, char input_char) {
    ???
}

/* Run the concatenated FSM for entire input string. */
int runRegexConcat(ConcatFSM *concatFsm, const char *str) {
    ???
}

int main() {
	/* Create our three FSMs objects. */
    FSM fsmA, fsmB;
    ConcatFSM concatFsm;
	
	/* Our two test case strings. */
    const char *testString = "Hello, world!";
    const char *testString2 = "Hablo, world!";
	
	/* Initialize our three FSMs. */
	initFSM(&fsmA, 'a');
    initFSM(&fsmB, 'b');
    initConcatFSM(&concatFsm, &fsmA, &fsmB);
	
	/* Test case 1. */
    if (runRegexConcat(&concatFsm, testString))
        printf("The string \"%s\" contains 'ab'.\n", testString);
    else
        printf("The string \"%s\" does not contain 'ab'.\n", testString);
	
	/* Test case 2.
       Remember to reset the FSM. */
	initConcatFSM(&concatFsm, &fsmA, &fsmB);
    if (runRegexConcat(&concatFsm, testString2))
        printf("The string \"%s\" contains 'ab'.\n", testString2);
    else
        printf("The string \"%s\" does not contain 'ab'.\n", testString2);

    return 0;
}