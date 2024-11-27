#include<stdio.h>
int main()
{
    int var=25;
    int *ptr=&var;
    printf("%d\n",*ptr);
    printf("%p\n",ptr);
    printf("%p",*ptr);
}
