#include<stdio.h>
#include<stdlib.h>
struct Root
{
    int data;
    struct Root *left;
    struct Root *right;
};
struct Root *insert(struct Root *root,int item)
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
        root->right=insert(root->right,item);
    }
    else
    {
        root->left=insert(root->left,item);
    }
    return root;
}
void in_order_traverse(struct Root *root)
{
    if(root==NULL)
        return;
    in_order_traverse(root->left);
    printf("%d\t",root->data);
    in_order_traverse(root->right);
}
int get_count(struct Root *root,int l,int h)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data>=l && root->data<=h)
    {
        return 1+get_count(root->left,l,h)+get_count(root->right,l,h);
    }
    else if(root->data<l)
    {
        return get_count(root->right,l,h);
    }
    else
    {
        return get_count(root->left,l,h);
    }
}
int main()
{
    int item,size,l,h;
    struct Root *root=NULL;
    printf("Enter size:\n");
    scanf("%d",&size);
    printf("Enter values to create a BST:\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&item);
        root=insert(root,item);
    }
    in_order_traverse(root);
    printf("\nEnter range [l,h]:\n");
    scanf("%d %d",&l,&h);
    printf("\nNumber of nodes in the given range:%d\n",get_count(root,l,h));
    return 0;
}
