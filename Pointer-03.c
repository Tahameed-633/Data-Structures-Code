#include<stdio.h>
int main()
{
    int n;
    int ar[n],*p,sum;
    scanf("%d",&n);
    p=&ar[0];
    for(int i=0;i<n;i++)
    {
        scanf("%d",p+i);
    }
    sum=sumArray(&ar[0],n);
    printf("%d",sum);
}
int sumArray(int *p,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
       sum=sum+*(p+i);
    }
    return sum;
}
