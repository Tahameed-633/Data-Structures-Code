#include<stdio.h>
int main()
{
    int ar[5],*p,sum=0;
    p=&ar[0];
    for(int i=0;i<5;i++)
    {
        scanf("%d", p+i);
    }
    for(int i=0;i<5;i++)
    {
        sum=sum+*(p+i);
    }
    printf("%d",sum);
}
