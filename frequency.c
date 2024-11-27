#include<stdio.h>
int main()
{
    int ar[50], freq[50], n, k, i, j;


    printf("Enter the number of elements: \n");
    scanf("%d", &n);


    printf("Input the array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
        freq[i] = 0;
    }


    for(i = 0; i < n; i++)
    {
        if(freq[i] == 0)
        {
            k = 1;

            for(j = i + 1; j < n; j++)
            {
                if(ar[i] == ar[j])
                {
                    k++;
                    freq[j] = -1;
                }
            }

            freq[i] = k;
        }
    }


    for(i = 0; i < n; i++)
    {
        if(freq[i] != -1)
        {
            printf("Frequency of the element %d is %d\n", ar[i], freq[i]);
        }
    }

    return 0;
}
