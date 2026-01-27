#include <stdio.h>
#include<stdbool.h>
int main()
{
    int n;                                                 
    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];                                              

    for (int i = 0; i < n; i++)                          
    {
        printf("Enter element %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("Array elements are:\n");                      
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
printf(" \n");
    int key;                                             
    printf("Enter Key value : ");
    scanf("%d", &key);
    bool flag;                                          
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

