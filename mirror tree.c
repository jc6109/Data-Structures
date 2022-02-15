#include<stdio.h>  // convert a tree into  its mirror tree
#include<stdlib.h>
int flag=1;

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





int addnode(struct node **q,int num)
{
    struct node *temp,*r,*parent;
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


int display(struct node *q)
{
    if(q!=NULL)
    {
        display(q->leftchild);

        printf(" %d ",q->data);

        display(q->rightchild);
    }
    return 0;
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
    temp=*q;
    *q=temp->link;
    temp->link=NULL;
    free(temp);
    return 0;
}


struct node * peek(struct lnode **q)
{
    struct lnode *temp;
    temp=*q;

    return temp->ptr;
}


int mirror(struct node **q,struct lnode **p)
{
    struct node *temp,*r;
    temp=*q;
   
   while(1)
   {
       while(temp!=NULL)
       {   
           r=temp->rightchild;
           temp->rightchild=temp->leftchild;
           temp->leftchild=r;
           push(p,temp);
           temp=temp->leftchild;
       }
       if(*p!=NULL)
       {
           temp=peek(p);
           pop(p);
           
           temp=temp->rightchild;
       }
       else
       {
           break;
       }
   }

}


int main()
{
    struct node *treeroot=NULL;
    struct lnode *listroot=NULL;
    

    addnode(&treeroot,5);
    addnode(&treeroot,3);
    addnode(&treeroot,4);
    addnode(&treeroot,2);
    addnode(&treeroot,1);
    addnode(&treeroot,7);
    addnode(&treeroot,6);
    addnode(&treeroot,9);
    addnode(&treeroot,8);
    
    printf("\noriginal tree");
    display(treeroot);

    mirror(&treeroot,&listroot);
     
    printf("\nmirror image"); 
    display(treeroot);


   return 0;
}
