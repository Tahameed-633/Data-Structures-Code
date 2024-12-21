#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};
void menu()
{
    printf("\n 1.Create binary search tree\n 2.Search element\n 3.Find maximum value\n 4.Find minimum element\n 5.Delete node\n 6.In Order traversal\n 7.Pre order traversal\n 8.Post Order traversal\n");
}
struct Node *insert_node(struct Node *root,int item)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    if(root==NULL)
    {
        root=new_node;
        root->left=NULL;
        root->data=item;
        root->right=NULL;
        return root;
    }
    else if(root->data>item)
    {
        root->left=insert_node(root->left,item);
    }
    else
    {
        root->right=insert_node(root->right,item);
    }
    return root;
}
void in_order_traversal(struct Node *root)
{
    if(root==NULL)
    {
        return;
    }
    in_order_traversal(root->left);
    printf("%d\t",root->data);
    in_order_traversal(root->right);

}
void pre_order_traversal(struct Node *root)
{
    if(root==NULL)
        return;
    printf("%d\t",root->data);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);

}
void post_order_traversal(struct Node *root)
{
    if(root==NULL)
        return;
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    printf("%d\t",root->data);

}

struct Node *search(struct Node *root,int key)
{
    if(root==NULL||root->data==key)
    {
        return root;
    }
    else if(key>root->data)
    {
        return search(root->right,key);
    }
    else
    {
        return search(root->left,key);
    }
}
struct Node *find_max(struct Node *root)
{
    if(root->right==NULL)
    {
        return root;
    }
    return find_max(root->right);
}
struct Node *find_min(struct Node *root)
{
    if(root->left==NULL)
    {
        return root;
    }
    return find_min(root->left);
}
struct Node *delete_node(struct Node *root,int item)
{
    if(root==NULL)
    {
        return root;
    }
    if(item< root->data)
    {
        root->left=delete_node(root->left,item);
    }
    else if(item>root->data)
    {
        root->right=delete_node(root->right,item);
    }
    else
    {
        if (root->left==NULL&&root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left==NULL)
        {
            struct Node *temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else if (root->right==NULL)
        {
            struct Node *temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        else
        {
            struct Node *temp=find_min(root->right);
            root->data=temp->data;
            root->right=delete_node(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
    int size,item,key,num,choice;
    struct Node *root=NULL,*value=NULL,*max=NULL,*min=NULL;
    while(1)
    {
        menu();
        printf("Please enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the size of the tree:\n");
            scanf("%d",&size);
            printf("Enter the elements to store in the tree:\n");
            for(int i=1; i<=size; i++)
            {
                scanf("%d",&item);
                root=insert_node(root,item);

            }
            break;
        case 2:
            printf("Enter the element to search:\n");
            scanf("%d",&key);
            value=search(root,key);
            if(value==NULL)
            {
                printf("%d is not an element of the binary search tree:\n",key);
            }
            else
            {
                printf("%d is an element of the binary search tree.\n",key);
            }
            break;
        case 3:
            max=find_max(root);
            printf("%d is the maximum value:\n",max->data);
            break;
        case 4:
            min=find_min(root);
            printf("%d is the minimum value.\n",min->data);
            break;
        case 5:
            printf("Enter the value to delete:\n");
            scanf("%d",&num);
            root=delete_node(root,num);
            break;
        case 6:
            printf("In order traversal:\n");
            in_order_traversal(root);
            break;
        case 7:
            printf("Pre order traversal:\n");
            pre_order_traversal(root);
            break;
        case 8:
            printf("Post order traversal:\n");
            post_order_traversal(root);
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }

    }
}

