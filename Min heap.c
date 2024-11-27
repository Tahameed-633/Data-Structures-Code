#include<stdio.h>
int left_child(int i)
{
    return 2*i;
}
int right_child(int i)
{
    return 2*i+1;
}
void min_heapify(int heap[],int heap_size,int i)
{
    int left,right,temp,smallest;
    left=left_child(i);
    right=right_child(i);
    if(left<=heap_size&&heap[left]<heap[i])
    {
        smallest=left;
    }
    else
    {
        smallest=i;
    }
    if(right<=heap_size && heap[right]<heap[smallest])
    {
        smallest=right;
    }
    if(i!=smallest)
    {
        temp=heap[smallest];
        heap[smallest]=heap[i];
        heap[i]=temp;
        min_heapify(heap,heap_size,smallest);
    }
}
void build_min_heap(int heap[],int heap_size)
{
    for(int i=heap_size/2;i>=1;i--)
    {
        min_heapify(heap,heap_size,i);
    }
}
int main()
{
    int heap[6]={0,3,6,5,1,4};
    int heap_size=5;
    build_min_heap(heap,heap_size);
    for(int i=1;i<=heap_size;i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
    return 0;
}
