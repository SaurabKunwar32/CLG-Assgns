#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the string is a valid C identifier
int isValidIdentifier(const char *identifier) {
    int state = 0; // Start at initial state

    // Process each character in the identifier string
    for (int i = 0; i < strlen(identifier); i++) {
        char current = identifier[i];
        
        switch (state) {
            case 0: // Initial state
                // Check if the first character is a letter or underscore
                if (isalpha(current) || current == '_') {
                    state = 1; // Move to valid identifier state
                } else {
                    state = 2; // Invalid character, go to reject state
                }
                break;

            case 1: // Valid identifier state
                // Check if the character is a letter, digit, or underscore
                if (isalnum(current) || current == '_') {
                    state = 1; // Stay in valid identifier state
                } else {
                    state = 2; // Invalid character, go to reject state
                }
                break;

            case 2: // Reject state
                // Once in reject state, we stay there
                return 0; // Identifier is not valid
        }
    }

    // If we end in a valid identifier state, return true
    return state == 1; // Valid identifier
}

int main() {
    char identifier[100];

    printf("Enter the C identifier: ");
    fgets(identifier, sizeof(identifier), stdin);
    identifier[strcspn(identifier, "\n")] = 0; // Remove newline character

    // Check if the input string is a valid C identifier
    if (isValidIdentifier(identifier)) {
        printf("'%s' is a valid C identifier.\n", identifier);
    } else {
        printf("'%s' is not a valid C identifier.\n", identifier);
    }

    return 0;
}
