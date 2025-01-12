#include<stdio.h>
#include<stdlib.h>
int left_child(int i)
{
    return 2*i;
}
int right_child(int i)
{
    return 2*i+1;
}
void reheap_up(int heap[],int size,int i)
{
    int l,r,largest,temp;
    l=left_child(i);
    r=right_child(i);
    if(l<=size && heap[l]>heap[i])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
    if(r<=size && heap[r]>heap[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        temp=heap[i];
        heap[i]=heap[largest];
        heap[largest]=temp;
        reheap_up(heap,size,largest);
    }
}

void build_max_heap(int heap[],int size)
{
    int i;
    for(i=size/2; i>=1; i--)
    {
        reheap_up(heap,size,i);
    }
}
void sort_heap(int heap[],int size)
{
    int temp;
    for(int i=size; i>1; i--)
    {
        temp=heap[1];
        heap[1]=heap[i];
        heap[i]=temp;
        size=size-1;
        reheap_up(heap,size,1);
    }

}
void delete_root(int heap[],int size)
{
    int temp;
    temp=heap[1];
    heap[1]=heap[size];
    size=size-1;
    reheap_up(heap,size,1);
}
int find_largest(int heap[])
{
    int largest=heap[1];
    return largest;
}
int find_smallest(int heap[],int size)
{
    int smallest;
    smallest=heap[size/2+1];
    for(int i=size/2+2;i<=size;i++)
    {
        if(heap[i]<smallest)
        {
            smallest=heap[i];
        }

    }
    return smallest;
}
void display_heap(int heap[], int size) {
    if (size < 1) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements:\n");
    for (int i = 1; i <= size; i++) {
        printf("%d\t", heap[i]);
    }
    printf("\n");
}

int main() {
    int size = 0;
    int *heap = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Build Max Heap\n");
        printf("2. Display Heap\n");
        printf("3. Find Largest Element\n");
        printf("4. Find Smallest Element\n");
        printf("5. Delete Root\n");
        printf("6. Sort Heap\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the heap: ");
                scanf("%d", &size);

                if (size <= 0) {
                    printf("Invalid size! Size must be positive.\n");
                    size = 0;
                    break;
                }

                heap = (int *)malloc((size + 1) * sizeof(int));
                if (heap == NULL) {
                    printf("Memory allocation failed.\n");
                    size = 0;
                    break;
                }

                printf("Enter the elements of the heap:\n");
                for (int i = 1; i <= size; i++) {
                    scanf("%d", &heap[i]);
                }

                build_max_heap(heap, size);
                printf("Max heap built successfully.\n");
                break;

            case 2:
                display_heap(heap, size);
                break;

            case 3:
                if (size < 1) {
                    printf("Heap is empty! Cannot find the largest element.\n");
                } else {
                    printf("Largest element: %d\n", find_largest(heap));
                }
                break;

            case 4:
                if (size < 1) {
                    printf("Heap is empty! Cannot find the smallest element.\n");
                } else {
                    printf("Smallest element: %d\n", find_smallest(heap, size));
                }
                break;

            case 5:
                delete_root(heap, size);
                break;

            case 6:
                if (size < 1) {
                    printf("Heap is empty! Cannot sort.\n");
                } else {
                    sort_heap(heap, size);
                    printf("Heap sorted in ascending order:\n");
                    display_heap(heap, size);
                }
                break;

            case 7:
                free(heap);
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}


