#include <stdio.h>
#include <string.h>

int isAccepted(const char *input) {
    int state = 0; // Start at the initial state

    // Process each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        char current = input[i];

        switch (state) {
            case 0: // Initial state
                if (current == '0') {
                    state = 1; // Move to state 1 on '0'
                }
                // Stay in state 0 on '1'
                break;

            case 1: // Last seen character was '0'
                if (current == '0') {
                    state = 2; // Move to state 2 on '0'
                } else {
                    state = 0; // Move back to state 0 on '1'
                }
                break;

            case 2: // Last two seen characters were '00'
                if (current == '1') {
                    state = 3; // Move to accepting state on '1' (now we've seen '001')
                } else {
                    // Stay in state 2 on '0'
                }
                break;

            case 3: // Accepting state (we have seen '001')
                // Stay in accepting state for any further input
                break;
        }
    }

    // Accept if we ended in the accepting state (State 3)
    return state == 3;
}

int main() {
    char input[100];

    printf("Enter the binary string : ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Check if the input string is accepted by the NFA
    if (isAccepted(input)) {
        printf("The string '%s' is accepted by the NFA.\n", input);
    } else {
        printf("The string '%s' is not accepted by the NFA.\n", input);
    }

    return 0;
}
