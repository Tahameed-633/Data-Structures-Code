#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_node(int item) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Error! Memory hasn't been allocated.\n");
        exit(1);
    }
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

void in_order_traverse(struct Node *node) {
    if (node == NULL) {
        return;
    }
    in_order_traverse(node->left);
    printf("%d -> ", node->data);
    in_order_traverse(node->right);
}

int main() {
    printf("In-order traversal:\n");

    struct Node *root = create_node(5);
    struct Node *left_child_1 = create_node(10);
    struct Node *right_child_1 = create_node(15);

    add_left_child(root, left_child_1);
    add_right_child(root, right_child_1);

    in_order_traverse(root);
    printf("NULL\n");

    return 0;
}
