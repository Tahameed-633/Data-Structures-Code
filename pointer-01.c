#include<stdio.h>
int main()
{
    int x=5,y=50;
    printf("x=%d,y=%d\n",x,y);
    swap(&x,&y);
    printf("x=%d,y=%d\n",x,y);
    return 0;
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
