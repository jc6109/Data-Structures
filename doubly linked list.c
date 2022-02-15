#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

int add_at_end(struct node **q,int num)
{
    struct node *temp,*r;
    temp=*q;
    
    if(*q==NULL)
     {
         temp=malloc(sizeof(struct node));
         temp->prev=NULL;
         temp->data=num;
         temp->next=NULL;
         *q=temp;
     }
     else
     {
         temp=*q;
         while(temp->next!=NULL)
          {
              temp=temp->next;
          }
          r=malloc(sizeof(struct node));
          r->prev=temp;
          r->data=num;
          r->next=NULL;
          temp->next=r;
     }
     return 0;
}

int display(struct node *q)
{
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    return 0;
}

int add_at_start(struct node **q,int num)
 {
     struct node *temp,*r;
     temp=*q;
     r=malloc(sizeof(struct node));
     r->prev=NULL;
     r->data=num;
     r->next=temp;
     temp->prev=r;
     *q=r;
     return 0;
 }
 
 int add_at_index(struct node **q,int num,int index)
 {
     struct node *temp,*r;
     int curr_pos=1;
     
     r=malloc(sizeof(struct node));
     r->prev=NULL;
     r->data=num;
     r->next=NULL;
     if(*q==NULL)
     {
         *q=r;
     }
     
 }






int main()
{
    struct node *p;
    p=NULL;
    
    add_at_end(&p,1);
    add_at_end(&p,2);
    add_at_end(&p,3);
    add_at_end(&p,4);
    add_at_end(&p,5);
    add_at_end(&p,6);
    add_at_end(&p,7);
    
    printf("\nadd at end   ");
    display(p);
    
    
    add_at_start(&p,10);
    add_at_start(&p,9);
    add_at_start(&p,8);
    
    printf("\nadd at start   ");
    display(p);
    
    
    add_at_index(&p,11,6);
    add_at_index(&p,12,1);
    add_at_index(&p,13,9);
    add_at_index(&p,14,12);
    add_at_index(&p,15,10);
    
    printf("\nadd at index   ");
    display(p);
    
    return 0;
    
}
