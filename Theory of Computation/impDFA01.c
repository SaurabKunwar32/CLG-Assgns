#include <stdio.h>
#include <string.h>

int isAccepted(const char *input) {
    int state = 0; // Start at initial state

    // Process each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        char current = input[i];

        if (current == '0') {
            if (state == 0) {
                state = 1; // Transition from state 0 to state 1
            } else if (state == 1) {
                state = 1; // Stay in state 1
            } else if (state == 2) {
                state = 1; // Transition from state 2 to state 1
            }
        } else if (current == '1') {
            if (state == 0) {
                state = 0; // Stay in state 0
            } else if (state == 1) {
                state = 2; // Transition from state 1 to state 2 (accepting state)
            } else if (state == 2) {
                state = 0; // Transition from state 2 to state 0
            }
        } else {
            // Invalid input character
            printf("Invalid character '%c' in input. Only '0' and '1' are allowed.\n", current);
            return 0; // Reject if an invalid character is found
        }
    }

    // Accept if in accepting state (State 2)
    return state == 2;
}

int main() {
    char input[100];

    printf("String must end with 01 \n");
    printf("Enter the binary string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Check if the input string is accepted by the DFA
    if (isAccepted(input)) {
        printf("The string '%s' is accepted by the DFA .\n", input);
    } else {
        printf("The string '%s' is not accepted by the DFA.\n", input);
    }

    return 0;
}
