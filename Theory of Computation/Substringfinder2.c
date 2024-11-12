#include <stdio.h>
#include <string.h>

// Function to extract substring from position `a` with `b` symbols
void substring2(char w[], int a, int b) {
    int len = strlen(w);
    
    // Check if the starting position is within the string bounds
    if (a < 0 || a >= len) {
        printf("Invalid starting position.\n");
        return;
    }

    // Adjust `b` if the number of symbols to be extracted exceeds the length
    if (a + b > len) {
        b = len - a;
    }

    printf("Extracted substring: ");
    for (int i = a; i < a + b; i++) {
        printf("%c", w[i]);
    }
    printf("\n");
}

int main() {
    char w[100];
    int a, b;

    printf("Enter the string: ");
    fgets(w, sizeof(w), stdin);
    w[strcspn(w, "\n")] = 0;  // Remove newline character

    printf("Enter the starting position: ");
    scanf("%d", &a);
    printf("Enter the number of symbols to extract: ");
    scanf("%d", &b);

    substring2(w, a, b);

    return 0;
}
