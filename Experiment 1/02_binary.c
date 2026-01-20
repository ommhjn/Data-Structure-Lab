#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element of array : ", i);
        scanf("%d", &arr[i]);
    }
    printf("Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf(" \n");
    int key;
    printf("Enter key value  : ");
    scanf("%d", &key);

    int low = 0;
    int high = n - 1;
    bool found = false;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            printf("%d found at index %d", key, mid);
            found = true;
            break;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
    }

    if (found == false)
    {
        printf("%d not found in array", key);
    }

    return 0;
}