#include <iostream>
#include <cstdlib>

using namespace std;

int capacity = 2;
int top = -1;
int* stack;

void resize() {
    int* new_stack = (int*)malloc(capacity * 2 * sizeof(int));  // Use malloc in C++
    if (new_stack == NULL) {
        cout << "Memory allocation failed! Can't resize." << endl;
        return;
    }

    for (int i = 0; i <= top; i++) {
        new_stack[i] = stack[i];
    }

    free(stack);
    stack = new_stack;
    capacity = 2 * capacity;
    cout << "Size of the stack increased to: " << capacity << endl;
}

void push(int x) {
    if (top == capacity - 1) {
        resize();
    }
    top = top + 1;
    stack[top] = x;
    cout << "Item pushed successfully: " << x << endl;
}

int pop() {
    if (top >= 0) {
        int value = stack[top];
        top = top - 1;
        return value;
    }
    cout << "Exception in pop! Empty Stack." << endl;
    return -1;
}

int peek() {
    if (top >= 0) {
        return stack[top];
    }
    cout << "Exception in peek! Empty stack." << endl;
    return -1;
}

int main() {
    cout << "Implementing stack in C++" << endl;


    stack = (int*)malloc(capacity * sizeof(int));
    if (stack == NULL) {
        cout << "Memory allocation failed." << endl;
        return 1;
    }


    peek();
    pop();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    cout << "Item peeked successfully: " << peek() << endl;
    push(70);
    cout << "Item popped successfully: " << pop() << endl;


    free(stack);

    return 0;
}

