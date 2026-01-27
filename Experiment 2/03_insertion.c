#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element on %d index : ", i);
        scanf("%d", &a[i]);
    }

    printf("Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            a[j] = key;
            j--;
        }
    }
    printf(" \n");
    printf("Sorted Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
