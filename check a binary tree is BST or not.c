#include<stdio.h>
#include<stdlib.h>
struct Root
{
    struct Root *left;
    int data;
    struct Root *right;
};
struct Root *insert(struct Root *root,int item)
{
    struct Root *new_node=(struct Root *)malloc(sizeof(struct Root));
    if(root==NULL)
    {
        root=new_node;
        root->left=NULL;
        root->right=NULL;
        root->data=item;
        return root;
    }
    if(item>root->data)
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
    {
        return;
    }
    in_order_traverse(root->left);
    printf("%d\t",root->data);
    in_order_traverse(root->right);
}
struct Root *search_max(struct Root *root)
{
  if(root->right==NULL)
  {
      return root;
  }
  return search_max(root->right);
}
struct Root *search_min(struct Root *root)
{
  if(root->left==NULL)
  {
      return root;
  }
  return search_min(root->left);
}
int is_BST(struct Root *root)
{
    if(root==NULL)
    {
        return 1;
    }
    if(root->left!=NULL && search_max(root->left)->data>=root->data)
       {
           return 0;
       }
        if(root->right!=NULL && search_min(root->right)<=root->left)
            {
                return 0;
            }
            return is_BST(root->left) && is_BST(root->right);

}
int main()
{
    int size,item;
    struct Root *root=NULL;
    printf("Enter size:\n");
    scanf("%d",&size);
    printf("Enter element:\n");
    for(int i=1;i<=size;i++)
    {
        scanf("%d",&item);
        root=insert(root,item);
    }
    in_order_traverse(root);
    if(is_BST(root))
        printf("True\n");
        else
            printf("False\n");
}

