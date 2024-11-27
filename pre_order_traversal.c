#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create_node(int item)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
    node->data = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void add_left_child(struct Node *parent, struct Node *child)
{
    if (parent != NULL)
    {
        parent->left = child;
    }
}
void add_right_child(struct Node *parent, struct Node *child)
{
    if (parent != NULL)
    {
        parent->right = child;
    }
}
void print_tree(struct Node *root)
{
    if (root != NULL)
    {
        printf(" %d", root->data);
        print_tree(root->left);
        print_tree(root->right);
    }
}

int main()
{
    printf("Implementing binary tree in C\n");

    struct Node *root = create_node(5);
    struct Node *left_child_1 = create_node(10);
    struct Node *right_child_1 = create_node(15);
    struct Node *left_child_2 = create_node(20);
    struct Node *right_child_2 = create_node(25);
    struct Node *left_child_3 = create_node(30);
    struct Node *right_child_3 = create_node(35);

    add_left_child(root, left_child_1);
    add_right_child(root, right_child_1);
    add_left_child(left_child_1, left_child_2);
    add_right_child(left_child_1, right_child_2);
    add_left_child(right_child_1, left_child_3);
    add_right_child(right_child_1, right_child_3);

    printf("Pre-order traversal of the binary tree:");
    print_tree(root);
    printf("\n");

    return 0;
}
