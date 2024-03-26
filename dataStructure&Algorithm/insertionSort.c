#include <stdio.h>
#include <conio.h>

void insertion(int[], int);
void main()
{
    int n, i;
    int a[100];
    printf("Enter the number of the data items:");
    scanf("%d", &n);
    printf("Enter %d data items:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("The data items before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    insertion(a, n);
    printf("\nThe data items after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    getch();
}

void insertion(int a[], int n)
{

    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        temp = a[i];
        j = i - 1;

        while ((temp < a[j]) && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
