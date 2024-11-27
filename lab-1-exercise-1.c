#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the number of elements:\n ");
    scanf("%d", &n);
    int *ar = (int *)malloc(n * sizeof(int));
    if (ar == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    printf("Array elements are:\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");

    int max=ar[0];
    for(int i=1; i<n; i++)
    {
        if(ar[i]>max)
        {
            max=ar[i];
        }
    }
    printf("Maximum element of the array is: %d\n",max);
    free(ar);
    return 0;
}
