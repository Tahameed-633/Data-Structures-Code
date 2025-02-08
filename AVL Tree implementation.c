#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
struct Node *create_node(int key)
{
    struct Node *node=(struct Node *)malloc(sizeof(struct Node));
    node->data=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}
int get_height(struct Node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    return node->height;
}
int max(int h1,int h2)
{
    return (h1>h2)?h1:h2;
}
int get_balance_factor(struct Node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    return get_height(node->left)-get_height(node->right);
}
struct Node *right_rotate(struct Node *y)
{
    struct Node *x=y->left;
    struct Node *t2=x->right;
    x->right=y;
    y->left=t2;
    y->height=1+max(get_height(y->left),get_height(y->right));
    x->height=1+max(get_height(x->left),get_height(x->right));
    return x;
}
struct Node *left_rotate(struct Node *x)
{
    struct Node *y=x->right;
    struct Node *t2=y->left;
    y->left=x;
    x->right=t2;
    y->height=1+max(get_height(y->left),get_height(y->right));
    x->height=1+max(get_height(x->left),get_height(x->right));
    return y;
}
struct Node *insert_node(struct Node *node,int key)
{
    if(node==NULL)
    {
        return create_node(key);
    }
    if(key>node->data)
    {
        node->right=insert_node(node->right,key);
    }
    else
    {
        node->left=insert_node(node->left,key);

    }

    node->height=1+max(get_height(node->left),get_height(node->right));
    int bf=get_balance_factor(node);
    //left of left
    if(bf>1&&key<node->left->data)
    {
        return right_rotate(node);
    }
    //right of right
    if(bf<-1&&key>node->right->data)
    {
        return left_rotate(node);
    }
    //left of right
    if(bf>1&&key>node->right->data)
    {
        node->left=left_rotate(node->left);
        return right_rotate(node);
    }
    //right of left
    if(bf<-1&&key<node->right->data)
    {
        node->right=right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}
void in_order_traverse(struct Node *root)
{
    if(root==NULL)
    {
        return;
    }
    in_order_traverse(root->left);
    printf("%d\t",root->data);
    in_order_traverse(root->right);
}
int main()
{
    struct Node *root=NULL;
    int size,item;
    printf("Enter the size of the tree:\n");
    scanf("%d",&size);
    printf("Enter the elements to store in the tree:\n");
    for(int i=1;i<=size;i++)
    {
        scanf("%d",&item);
        root=insert_node(root,item);
    }
    printf("In order traversal:\n");
    in_order_traverse(root);
    printf("\nHeight of the AVL Tree:%d\n",get_height(root));
}

