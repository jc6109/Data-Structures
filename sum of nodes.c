#include<stdio.h>  //sum of all nodes in a tree
#include<stdlib.h>
int sum=0;


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

int inorder(struct node *q)
{
    if(q!=NULL)
    {
        inorder(q->leftchild);

        printf(" %d ",q->data);sum=sum+q->data;

        inorder(q->rightchild);
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
    
    printf("\ntree is ");
    inorder(treeroot);

    printf("\nsum of all  nodes  = %d ",sum);
    return 0;
}
