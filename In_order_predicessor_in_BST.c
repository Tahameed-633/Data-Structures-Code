#include<stdio.h>
#include<stdlib.h>
struct Root
{
    int data;
    struct Root *left;
    struct Root *right;
};
struct Root *find_rightmost(struct Root *root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;

}
struct Root *find_predecessor(struct Root *root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    if(key==root->data && root->left!=NULL)
    {
        return find_rightmost(root->left);
    }
    struct Root *pred=NULL;
    struct Root *current=root;
    while(current!=NULL)
    {
        if(key>current->data)
        {
            pred=current;
            current=current->right;
        }
        else if(key<current->data)
        {
            pred=current;
            current=current->left;
        }
        else
        {
            break;
        }
    }
    return pred;

}
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
void in_order_traversal(struct Root *root)
{
    if(root==NULL)
    {
        return;
    }
    in_order_traversal(root->left);
    printf("%d\t",root->data);
    in_order_traversal(root->right);
}
int main()
{
    int size,item,key;
    struct Root *root=NULL;
    printf("Enter size:\n");
    scanf("%d",&size);
    printf("Enter item:\n");
    for(int i=1; i<=size; i++)
    {
        scanf("%d",&item);
        root=insert(root,item);
    }
    printf("\n");
    in_order_traversal(root);

    printf("\nEnter key:\n");
    scanf("%d",&key);
    struct Root *preed=find_predecessor(root,key);
   if(preed!=NULL)
     printf("predecessor of %d is %d\n",key,preed->data);
   else
   printf("Predecessor does n't exist.");



}
