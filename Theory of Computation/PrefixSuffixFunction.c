#include <stdio.h>
#include <string.h>

// Function to remove leading symbols
void prefix2(char w[], int num) {
    int len = strlen(w);
    
    // Check if the number of symbols to remove is greater than the length of the string
    if (num >= len) {
        printf("The suffix is: (empty string)\n");
        return;
    }

    // Display the result after removing leading symbols
    printf("The suffix is: %s\n", &w[num]);
}

// Function to remove trailing symbols
void suffix2(char w[], int n) {
    int len = strlen(w);
    
    // Check if the number of symbols to remove is greater than the length of the string
    if (n >= len) {
        printf("The prefix is: (empty string)\n");
        return;
    }

    // Temporarily replace the end of the string with null character
    w[len - n] = '\0'; // Modify the string to remove trailing symbols
    printf("The prefix is: %s\n", w);
}

int main() {
    char w[100];
    int num, n;

    printf("Enter the string: ");
    fgets(w, sizeof(w), stdin);
    w[strcspn(w, "\n")] = 0;  // Remove newline character

    printf("Enter the number of leading symbols to remove: ");
    scanf("%d", &num);
    prefix2(w, num);

    printf("Enter the number of trailing symbols to remove: ");
    scanf("%d", &n);
    suffix2(w, n);

    return 0;
}
