#include<stdio.h>
#include<stdlib.h>
struct Root
{
    int data;
    struct Root *left;
    struct Root *right;
};
struct Root *insert_node(struct Root *root,int item)
{

    struct Root *new_node=(struct Root *)malloc(sizeof(struct Root));
    if(root==NULL)
    {
        root=new_node;
        root->left=NULL;
        root->data=item;
        root->right=NULL;
        return root;
    }
    else if(item>root->data)
    {
        root->right=insert_node(root->right,item);
    }
    else
    {
        root->left=insert_node(root->left,item);
    }
    return root;
}
int get_height(struct Root *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left_height=get_height(root->left);
    int right_height=get_height(root->right);
    if(left_height>right_height)
    {
        return 1+left_height;
    }
    return 1+right_height;
}
void in_order_traverse(struct Root *root)
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
    int size,item;
    struct Root *root=NULL;
    printf("Enter the size of the BST:\n");
    scanf("%d",&size);
    printf("Enter the elements to store in the BST:\n");
    for(int i=1; i<=size; i++)
    {
        scanf("%d",&item);
        root=insert_node(root,item);
    }
    in_order_traverse(root);
    printf("\nHeight of the BST is:%d\n",get_height(root));
    return 0;
}
