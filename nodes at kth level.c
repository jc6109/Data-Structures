#include<stdio.h> // print nodes at kth level
#include<stdlib.h>

int k,count=0,checkpoint=0;

struct node
{
    struct node *leftchild;
    int data;
    struct node *rightchild;
};
struct lnode
{
    struct node *ptr;
    int listcount;
    struct lnode *link;
};

int addnode(struct node **q,int num);
int traverse(struct node **q,struct lnode **p);
int push(struct lnode **q,struct node *p,int c);
int pop(struct lnode **q);
struct node * peek(struct lnode **q,int *c);


int main()
{
    struct node *root=NULL;
    struct lnode *lroot=NULL;


    printf("\nenter k");  scanf("%d",&k);

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

    
    printf("\n nodes at level %d is  ",k);
    traverse(&root,&lroot);
    if(checkpoint==0)
    {
        printf("  no nodes at this value of k");
    }

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



int traverse(struct node **q,struct lnode **p)
{
    struct node *temp;
    int count=0;
    temp=*q;
    while(1)
    {
        while(temp!=NULL)
        {
            push(p,temp,count);
            temp=temp->leftchild;count++;
        }
        if(*p!=NULL)
        {
            temp=peek(p,&count);
            pop(p);
            
            temp=temp->rightchild;count++;
        }
        else
        {
            break;
        }

    }
    return 0;

}

int push(struct lnode **q,struct node *p,int c)
{
  struct lnode *temp;
   temp=malloc(sizeof(struct lnode));
   temp->ptr=p;
   temp->listcount=c;
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
        if(temp->listcount==k)
        {
            printf(" %d ",temp->ptr->data); checkpoint=1;

        }
        *q=temp->link;
        temp->link=NULL;
        free(temp);
        return 0;
    }
}

struct node * peek(struct lnode **q,int *c)
{
    struct lnode *temp;
    temp=*q;
    *c=temp->listcount;
    return temp->ptr;

}
