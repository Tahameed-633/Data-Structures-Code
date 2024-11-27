#include<iostream>
using namespace std;

int capacity = 5;
int *queue;
int rear = -1, front = 0, total_item = 0;

// Function to check if the queue is empty
bool isEmpty()
{
    return total_item == 0;
}

// Function to resize the queue and handle circular nature
void resize()
{
    int *new_queue = new int[2 * capacity]; // C++ dynamic allocation
    if (new_queue == nullptr)
    {
        cout << "Memory allocation unsuccessful. Can't re-allocate memory." << endl;
        return;
    }

    // Copy elements from old queue to new queue in correct order
    for (int i = 0; i < total_item; ++i)
    {
        new_queue[i] = queue[(front + i) % capacity]; // Handle circular indexing
    }

    delete[] queue; // Free the old queue memory
    queue = new_queue;

    // Update front and rear to reflect new positions
    front = 0;
    rear = total_item - 1;  // Rear will now be at the last item
    capacity *= 2;  // Double the capacity
    cout << "Capacity of the queue increased to: " << capacity << endl;
}

// Function to enqueue an item into the queue
void enqueue(int item)
{
    if (total_item == capacity)
    {
        resize();
    }
    rear = (rear + 1) % capacity;
    queue[rear] = item;
    total_item++;
}

// Function to print the queue
void print_queue()
{
    cout << "Queue:" << endl;
    for (int i = 0; i < capacity; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

// Function to dequeue an item from the queue
int dequeue()
{
    if (isEmpty())
    {
        cout << "Sorry, queue is empty" << endl;
        return -1;
    }
    int front_item = queue[front];
    queue[front] = -1;
    front = (front + 1) % capacity;
    total_item--;
    return front_item;
}

int main()
{
    cout << "Implementing dynamic circular queue in C++" << endl;


    queue = new int[capacity];
    if (queue == nullptr)
    {
        cout << "Memory allocation unsuccessful" << endl;
        return -1;
    }

    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    print_queue();

    enqueue(60);
    cout << "Dequeued item: " << dequeue() << endl;
    print_queue();

    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);
    enqueue(110);
    print_queue();


    delete[] queue;

    return 0;
}

