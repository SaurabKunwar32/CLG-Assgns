#include <stdio.h>
#include <conio.h>

void selection(int[], int);
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
    selection(a, n);
    printf("\nThe data items after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    getch();
}

void selection(int a[], int n)
{
    int i, j, temp, index, least;

    for (i = 0; i < n; i++)
    {
        least = a[i];
        index = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < least)
            {
                least = a[j];
                index = j;
            }
        }
        if (i != index)
        {
            temp = a[i];
            a[i] = a[index];
            a[index] = temp;
        }
    }
}
