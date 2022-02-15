#include<stdio.h> // number of leaf nodes.
#include<stdlib.h>

struct node
{
    struct node *leftchild;
    int data;
    struct node *rightchild;
};
struct lnode
{
    struct node *ptr;
    struct lnode *link;
};

int addnode(struct node **q,int num);
int count(struct node **q,struct lnode **p);
int push(struct lnode **q,struct node *p);
int pop(struct lnode **q);
struct node * peek(struct lnode **q);

int main()
{
    struct node *root=NULL;
    struct lnode *lroot=NULL;

    addnode(&root,5);
    addnode(&root,3);
    addnode(&root,4);
    addnode(&root,2);
    addnode(&root,1);
    addnode(&root,7);
    addnode(&root,6);
    addnode(&root,9);
    addnode(&root,8);
    addnode(&root,0);

    

    printf("total leaf nodes are %d ",count(&root,&lroot));


    return 0;
}

int  addnode(struct node **q,int num)
{
    struct node *temp,*parent,*r;
    int flag=1;
        r=malloc(sizeof(struct node));
        r->leftchild=NULL;
        r->rightchild=NULL;
        r->data=num;

    
    if(*q==NULL)
    {
        *q=r;
    }
    else
    {
        temp=*q;
        while(temp!=NULL)
        {
            if(num<temp->data)
            {
                parent=temp;
                temp=temp->leftchild;flag=1;
            }
            else
            {
                parent=temp;
                temp=temp->rightchild;flag=2;
            }
        
        }
        if(flag==1)
        {
          parent->leftchild=r;
          return 0;  
        }
        else if(flag==2)
        {
            parent->rightchild=r;
            return 0;
        }
    }

}



int count(struct node **q,struct lnode **p)
{
    struct node *temp;
    int count=0;
    temp=*q;
    while(1)
    {
        while(temp!=NULL)
        {
            push(p,temp);
            temp=temp->leftchild;
        }
        if(*p!=NULL)
        {
            temp=peek(p);
            pop(p);
            if(temp->leftchild==NULL&&temp->rightchild==NULL)
            {
                count++;
            }
            temp=temp->rightchild;
        }
        else
        {
            break;
        }

    }
    return count;

}

int push(struct lnode **q,struct node *p)
{
  struct lnode *temp;
   temp=malloc(sizeof(struct lnode));
   temp->ptr=p;
   temp->link=*q;
   *q=temp;
   return 0;

}
int pop(struct lnode **q)
{
    struct lnode *temp;
    if(*q==NULL)
    {
        return 0;
    }
    else
    {
        temp=*q;
        *q=temp->link;
        temp->link=NULL;
        free(temp);
        return 0;
    }
}

struct node * peek(struct lnode **q)
{
    struct lnode *temp;
    temp=*q;
    return temp->ptr;

}
