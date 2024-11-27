#include<stdio.h>
int Binary_Search(int a[], int n, int x);
int main()
{
    int ar[10], n, temp,x;

    printf("Enter the number of elements of the array\n");
    scanf("%d", &n);
    printf("Input the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (ar[j] > ar[j+1])
            {

                temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }


    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }

    printf("\n");
    printf("Input the element to search: \n");
    scanf("%d",&x);
    int index=Binary_Search(ar,n,x);
    printf("The element is at index: %d\n",index);

    return 0;
}
int Binary_Search(int ar[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int middle = (left+right) / 2;
        if (ar[middle] == x) {
            return middle;
        } else if (x < ar[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}
