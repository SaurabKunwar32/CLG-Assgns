#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char stack[MAX_STACK_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack *s) {
    s->top = -1; // Empty stack
}

// Function to push an element onto the stack
void push(Stack *s, char element) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->stack[++(s->top)] = element;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (s->top >= 0) {
        return s->stack[(s->top)--];
    } else {
        return '\0'; // Return null character if stack is empty
    }
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to implement the PDA
int isAccepted(const char *input) {
    Stack stack;
    initializeStack(&stack);
    
    // Process each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        char current = input[i];

        switch (current) {
            case '0':
                push(&stack, 'Z'); // Push a symbol for '0'
                break;
            case '1':
                if (!isEmpty(&stack)) {
                    pop(&stack); // Pop a symbol for '1'
                } else {
                    return 0; // More '1's than '0's
                }
                break;
            default:
                return 0; // Invalid input
        }
    }

    // The input is accepted if the stack is empty at the end
    return isEmpty(&stack);
}

int main() {
    char input[100];

    printf("Enter the binary string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Check if the input string is accepted by the PDA
    if (isAccepted(input)) {
        printf("The string '%s' is accepted by the PDA .\n", input);
    } else {
        printf("The string '%s' is not accepted by the PDA.\n", input);
    }

    return 0;
}
