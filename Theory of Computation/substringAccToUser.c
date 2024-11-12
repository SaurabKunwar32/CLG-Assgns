#include <stdio.h>
#include <string.h>

// Function to extract substring from start (a) to end (b)
void substring(char w[], int a, int b) {
    int len = strlen(w);
    if (a < 0 || b >= len || a > b) {
        printf("Invalid positions for substring.\n");
        return;
    }

    printf("Substring from the position %d to %d: ", a, b);
    for (int i = a; i <= b; i++) {
        printf("%c", w[i]);
    }
    printf("\n");
}

int main() {
    char w[100];
    int a, b;

    printf("Enter the string: ");
    fgets(w, sizeof(w), stdin);
    w[strcspn(w, "\n")] = 0;

    printf("Enter the starting position: ");
    scanf("%d", &a);
    printf("Enter the ending position: ");
    scanf("%d", &b);

    substring(w, a, b);

    return 0;
}
