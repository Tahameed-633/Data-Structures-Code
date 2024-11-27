#include<stdio.h>

int left_index(int root_index) {
    return 2 * root_index;
}

int right_index(int root_index) {
    return 2 * root_index + 1;
}

void max_heapify(int heap[], int heap_size, int root_index) {
    int left, right, temp, largest;
    left = left_index(root_index);
    right = right_index(root_index);

    if (left <= heap_size && heap[left] > heap[root_index]) {
        largest = left;
    } else {
        largest = root_index;
    }

    if (right <= heap_size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != root_index) {

        temp = heap[root_index];
        heap[root_index] = heap[largest];
        heap[largest] = temp;


        max_heapify(heap, heap_size, largest);
    }
}

void build_max_heap(int heap[], int heap_size) {
    for (int i = heap_size / 2; i >= 1; i--) {
        max_heapify(heap, heap_size, i);
    }
}

int main() {
    int heap[6] = {0, 3, 6, 5, 1, 4};
    int heap_size = 5;

    build_max_heap(heap, heap_size);

    printf("Max-Heap:\n");
    for (int i = 1; i <= heap_size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    return 0;
}
