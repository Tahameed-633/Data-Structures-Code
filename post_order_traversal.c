#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

};
struct Node *create_node(int item)
{
    struct Node *node=(struct Node *)malloc(sizeof(struct Node));
    if(node==NULL)
    {
        printf("Error! Can't allocate memory.\n");
        return -1;
    }
    node->data=item;
    node->left=NULL;
    node->right=NULL;
    return node;
}
void add_left_child(struct Node *parent,struct Node *child)
{
    parent->left=child;
}
void add_right_child(struct Node *parent,struct Node *child)
{
    parent->right=child;
}
void post_traverse(struct Node *root)
{
    // Check if the root is NULL
    if(root == NULL)
        return;

    // Traverse the left subtree
    post_traverse(root->left);

    // Traverse the right subtree
    post_traverse(root->right);

    // Visit the root node
    printf("%d -> ", root->data);
}

int main()
{
    struct Node *root=create_node(5);
    struct Node *left_child_1=create_node(10);
    struct Node *right_child_1=create_node(15);
    struct Node *left_child_2=create_node(20);
    struct Node *right_child_2=create_node(25);
    struct Node *left_child_3=create_node(30);
    struct Node *right_child_3=create_node(35);
    add_left_child(root,left_child_1);
    add_right_child(root,right_child_1);
    add_left_child(left_child_1,left_child_2);
    add_right_child(left_child_1,right_child_2);
    add_left_child(left_child_2,left_child_3);
    add_right_child(left_child_2,right_child_3);
    post_traverse(root);
    printf("NULL\n");
    return 0;
}
