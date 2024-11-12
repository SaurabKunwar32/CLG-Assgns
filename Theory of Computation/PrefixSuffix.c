#include <stdio.h>
#include <string.h>

// Function to display all prefixes of the string
void prefix(char W[]) {
    int len = strlen(W);
    printf("All prefixes:\n");
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", W[j]);
        }
        printf("\n");
    }
}

// Function to display all suffixes of the string
void suffix(char W[]) {
    int len = strlen(W);
    printf("\nAll suffixes:\n");
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            printf("%c", W[j]);
        }
        printf("\n");
    }
}

int main() {
    char W[100];
    
    printf("Enter the string: ");
    fgets(W, sizeof(W), stdin);
    W[strcspn(W, "\n")] = 0;  // Remove newline character

    prefix(W);
    suffix(W);

    return 0;
}
