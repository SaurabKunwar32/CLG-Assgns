#include <stdio.h>
#include <conio.h>

void bubble(int[], int);
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
    bubble(a, n);
    printf("\nThe data items after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    getch();
}

void bubble(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            temp = a[j];
            if (a[j] > a[j + 1])
            {
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
