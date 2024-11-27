#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *p = (int *)malloc(n * sizeof(int));
    if (p == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", p+i);
    }

    int newSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] >= 0)
        {
            p[newSize++] = p[i];
        }
    }

    printf("Modified array: ");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    free(p);
    return 0;
}
