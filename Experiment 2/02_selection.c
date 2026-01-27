#include <stdio.h>

int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int i, j;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element on %d index : ", i);
        scanf("%d", &a[i]);
    }

    printf("Array : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    int temp;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])

                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("Sorted Array : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}