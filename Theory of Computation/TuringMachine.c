#include <stdio.h>
#include <string.h>

#define TAPE_SIZE 100

// Function to simulate the Turing Machine
int turingMachine(char *tape) {
    int head = 0; // Current position on the tape
    int state = 0; // Initial state

    while (1) {
        char current = tape[head];

        switch (state) {
            case 0: // Looking for a 0 to mark
                if (current == '0') {
                    tape[head] = 'X'; // Mark the 0
                    head++; // Move right
                    state = 1; // Move to the next state
                } else if (current == '1' || current == '\0') {
                    // If we find a 1 before all 0s are marked, reject
                    return 0; 
                } else {
                    // Current is not 0, just move right
                    head++;
                }
                break;

            case 1: // Looking for a 1 to match the marked 0
                if (current == '1') {
                    tape[head] = 'Y'; // Mark the 1
                    head = 0; // Move head back to the start of the tape
                    state = 0; // Go back to state 0 to find the next 0
                } else if (current == '\0') {
                    // If we reach the end of the tape and there are unmarked 0s, reject
                    return 0;
                } else {
                    // Continue moving right
                    head++;
                }
                break;
        }

        // Check for out of bounds
        if (head >= TAPE_SIZE) {
            return 0; // Reject if we go out of bounds
        }

        // Check for acceptance condition
        if (state == 0 && (current == '\0' || current == 'Y')) {
            // If we reach the end of the tape and all 0s are marked with X and all 1s with Y
            for (int i = 0; i < TAPE_SIZE; i++) {
                if (tape[i] == '0') return 0; // Found unmarked 0
                if (tape[i] == '1') return 0; // Found unmarked 1
            }
            return 1; // Accept
        }
    }

    return 0; // Default reject case
}

int main() {
    char tape[TAPE_SIZE];

    printf("Enter the binary string : ");
    fgets(tape, sizeof(tape), stdin);
    tape[strcspn(tape, "\n")] = 0; // Remove newline character

    // Run the Turing Machine
    if (turingMachine(tape)) {
        printf("The string '%s' is accepted by the Turing Machine .\n", tape);
    } else {
        printf("The string '%s' is not accepted by the Turing Machine.\n", tape);
    }

    return 0;
}
