//iterative model of in order

#include<stdio.h>
#include<stdlib.h>
int flag=1;

struct treenode
{
    struct treenode *leftchild;
    int data;
    struct treenode *rightchild;
};

struct listnode
{
    struct treenode *ptr;
    struct listnode *link;
};
int addnode(struct treenode **q,int num)
{
    struct treenode *temp,*r,*parent;
    r=malloc(sizeof(struct treenode));
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

int inorder_display(struct treenode *q)
{
    if(q!=NULL)
    {
        inorder_display(q->leftchild);

        printf(" %d ",q->data);

        inorder_display(q->rightchild);
    }
    return 0;
}

int inorder_push(struct listnode **q,struct treenode *p)
{
    struct listnode *temp;
    temp=malloc(sizeof(struct listnode));
    temp->ptr=p;
    temp->link=*q;
    *q=temp;
}
int inorder_pop(struct listnode **q,struct treenode **p)
{
    struct listnode *temp;
    if(*q==NULL)
    {
        *p=NULL;
    }
    else
    {
    temp=*q;
    *q=temp->link;
    temp->link=NULL;
    printf(" %d ",(temp->ptr)->data);
    *p=temp->ptr;
    }
    return 0;
} 

int inorder(struct treenode **q,struct listnode **p)
{
   struct treenode*temp;
   temp=*q;
   while(temp!=NULL)
   {
       if(temp->leftchild!=NULL||temp->leftchild!=NULL)
       {  inorder_push(p,temp);
          temp=temp->leftchild;

       }
       else
       {
           printf(" %d ",temp->data);
           inorder_pop(p,&temp); 
           if(temp==NULL)
           {return 0;
           }
           else
           {
           temp=temp->rightchild;
            while(temp==NULL)
            {
                inorder_pop(p,&temp);
                temp=temp->rightchild;
            }
           }
           

       }
   }
   return 0;

}
int preorder_push(struct listnode **q,struct treenode *p)
{
    struct listnode *temp;
    temp=malloc(sizeof(struct listnode));
    temp->ptr=p;
    temp->link=*q;
    *q=temp;

    return 0;

}

int preorder_pop(struct listnode **q,struct treenode **p)
{
    struct listnode *temp;
    if(*q==NULL)
    {
        *p=NULL;
    }
    else
    {
    temp=*q;
    *q=temp->link;
    temp->link=NULL;
    *p=temp->ptr;
    }
    return 0;
}

int preorder(struct treenode **q,struct listnode **p)
{
    struct treenode *temp;
    temp=*q;
    while(temp!=NULL)
    {
        if(temp->leftchild!=NULL||temp->rightchild!=NULL)
         {
             printf(" %d ",temp->data);
             preorder_push(p,temp);
             temp=temp->leftchild;
         }
         else
         {
             printf(" %d ",temp->data);
             preorder_pop(p,&temp);
             while(temp->rightchild==NULL)
             {
                 preorder_pop(p,&temp);
                 if(temp==NULL)
                 {
                     return 0;
                 }
             }
             temp=temp->rightchild;
            
         }
    }    
         
}

int main()
{
    struct listnode *listroot=NULL;
    struct treenode *treeroot=NULL;

    addnode(&treeroot,5);printf("\ninorder traversal ");inorder_display(treeroot);
    addnode(&treeroot,3);printf("\ninorder traversal ");inorder_display(treeroot);
    addnode(&treeroot,7);printf("\ninorder traversal ");inorder_display(treeroot);
    addnode(&treeroot,4);printf("\ninorder traversal ");inorder_display(treeroot);
    addnode(&treeroot,2);printf("\ninorder traversal ");inorder_display(treeroot);
    addnode(&treeroot,1);printf("\ninorder traversal ");inorder_display(treeroot);
    addnode(&treeroot,9);printf("\ninorder traversal ");inorder_display(treeroot);
    addnode(&treeroot,8);printf("\ninorder traversal ");inorder_display(treeroot);
    addnode(&treeroot,6);printf("\ninorder traversal ");inorder_display(treeroot);

    printf("\n\ninorder traversal ");inorder_display(treeroot);

    printf("\ninorder iterative ");
    inorder(&treeroot,&listroot);
    
    printf("\npreorder iterative ");
    preorder(&treeroot,&listroot);
    
    printf("\ngoooood");
    return 0;
    
}
