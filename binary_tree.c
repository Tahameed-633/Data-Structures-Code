#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_node(int item) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void add_left_child(struct Node *parent, struct Node *child) {
    parent->left = child;
}

void add_right_child(struct Node *parent, struct Node *child) {
    parent->right = child;
}

int main() {
    printf("Implementing binary tree in C\n");


    struct Node *root = create_node(15);
    struct Node *left_child = create_node(5);
    struct Node *right_child = create_node(3);


    add_left_child(root, left_child);
    add_right_child(root, right_child);


    printf("Root: %d ; Left child: %d ; Right child: %d ;\n", root->data, root->left->data, root->right->data);

    return 0;
}
