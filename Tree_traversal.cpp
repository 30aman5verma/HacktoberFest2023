using namespace std;
#include<iostream>
#include<limits.h>
#include<stdlib.h>

struct tree
{
    int info;
    struct tree *right;
    struct tree *left;
};

struct tree * addnode(struct tree *ptr,int item)
{
    if(ptr == NULL)
    {
        ptr = (struct tree *)malloc(sizeof(struct tree));
        ptr->info = item;
        ptr->right = NULL;
        ptr->left = NULL;
    }
    else if(item<ptr->info)
    {
        ptr->left = addnode(ptr->left,item);
    }
    else
    {
        ptr->right = addnode(ptr->right,item);
    }
    return ptr;
}

void inorder(struct tree *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        inorder(ptr->left);
        cout<<ptr->info<<"\t";
        inorder(ptr->right);
    }
}

int main()
{
    int num;
    int op;
    struct tree *root = NULL;
    do
    {
        cout<<"\n\nTree Traversal Operations : ";
        cout<<"\n1. Add";
        cout<<"\n2. Inorder";
        cout<<"\n0. Exit";
        cout<<"\nEnter Choice : ";
        cin>>op;
        if(op==0) break;
        else if(op == 1)
        {
            cout<<"Enter the number to be added : ";
            cin>>num;
            root = addnode(root,num);
            cout<<"\nNode Created";
        }
        else if(op==2)
        {
            cout<<"\nResult of inorder traversal : \n";
            inorder(root);
        }
    }while(op!=0);
}
