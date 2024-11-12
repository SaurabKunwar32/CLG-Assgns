#include <stdio.h>
#include <string.h>

int isAccepted(const char *input) {
    int state = 0; // Start at initial state

    // Process each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        switch (state) {
            case 0: // Initial state
                if (input[i] == '1') {
                    state = 1; // Move to state 1 on '1'
                }
                // Stay in state 0 on '0'
                break;

            case 1: // Last seen character was '1'
                if (input[i] == '0') {
                    state = 2; // Move to state 2 on '0'
                }
                // Stay in state 1 on '1'
                break;

            case 2: // Last seen characters are '10'
                if (input[i] == '1') {
                    state = 3; // Move to accepting state on '1'
                } else {
                    // Revert to state 0 on '0'
                    state = 0;
                }
                break;

            case 3: // Last seen characters are '101' (accepting state)
                // Once in this state, we stay in accepting state for any further input
                break; // Stay in accepting state
        }
    }

    // Accept if we ended in the accepting state (State 3)
    return state == 3 || state == 2 || state == 1; // Accept if we reached state 3
}

int main() {
    char input[100];            

    printf("String has substrings 101\n");
    printf("Enter the binary string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Check if the input string is accepted by the DFA
    if (isAccepted(input)) {
        printf("The string '%s' is accepted by the DFA (it contains '101').\n", input);
    } else {
        printf("The string '%s' is not accepted by the DFA.\n", input);
    }

    return 0;
}
