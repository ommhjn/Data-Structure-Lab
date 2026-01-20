#include <stdio.h>
#include<stdbool.h>
int main()
{
    int n;                                                  // Size of array
    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];                                              // Declaring array

    for (int i = 0; i < n; i++)                            // Loop for taking array element as input from user
    {
        printf("Enter element %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("Array elements are:\n");                       // Loop for printing back array
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
printf(" \n");
    int key;                                              // Taking in key value that is need to found
    printf("Enter Key value : ");
    scanf("%d", &key);
    bool flag;                                            // Flag variable 
    for (int i = 0; i < n; i++)
    {
        if (key == a[i])
        {
            printf("%d found at %d index!", key, i);
            flag = true;
        }
    }
    if (flag == false)
    {
        printf("%d not found in array!", key);
    }

    return 0;
}
