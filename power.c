#include<stdio.h>
#include<math.h>
int power(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        int t=x*pow(x,n-1);
        return t;
    }
}
int main()
{
    int x,n;
    printf("Enter the value of x:\n");
    scanf("%d",&x);
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    printf("%d to the power %d is:%d\n",x,n,power(x,n));
}
