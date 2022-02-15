#include<stdio.h>
#include<stdlib.h>    //find min element in the tree.

struct node
{
    struct node *leftchild;
    int data;
    struct node *rightchild;
};

int addnode(struct node **q,int num)
{
    struct node *temp,*r,*parent;
    int flag=1;
    r=malloc(sizeof(struct node));
    r->leftchild=NULL;
    r->data=num;
    r->rightchild=NULL;
    if(*q==NULL)
    {
        *q=r;return 0;
    }
    else
    {  temp=*q;parent=temp;
       while(temp!=NULL)
       {
           if(num<temp->data)
            {   parent=temp;
                temp=temp->leftchild;flag=1;
            }
            else  if(num>temp->data)
            {    parent=temp;
                temp=temp->rightchild;flag=2;
            }
       }
       if(flag==1)
       {
           parent->leftchild=r;return 0;
       }
       else if(flag==2)
       {
           parent->rightchild=r;return 0;
       }

    }
    
    
}


int find(struct node **q)
{
    struct node *temp;
    if(*q==NULL)
    {
        printf("\nno element in the tree");
        return -1;
    }
    else
    {
        temp=*q;
        while(temp->leftchild!=NULL)
        {
            temp=temp->leftchild;
        }

        return temp->data;
    }

}

int main()
{  
    struct node *treeroot=NULL;

    addnode(&treeroot,5);
    addnode(&treeroot,3);
    addnode(&treeroot,4);
    addnode(&treeroot,2);
    addnode(&treeroot,1);
    addnode(&treeroot,7);
    addnode(&treeroot,6);
    addnode(&treeroot,9);
    addnode(&treeroot,8);

    printf("minimum element = %d ",find(&treeroot));
    return 0;
}
