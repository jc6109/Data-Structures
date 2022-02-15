#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int add_node(struct node **q,int num)
{
   struct node *temp,*r;
   temp=*q;
   
   if(*q==NULL)
    {
        r=malloc(sizeof(struct node));
        r->data=num;
        r->link=NULL;
        *q=r;
        return 0;
    }
    
    else
    {
        temp=*q;
        
        while(temp->link!=NULL)
         {
             temp=temp->link;
             
         }
         
         r=malloc(sizeof(struct node));
         r->data=num;
         r->link=NULL;
         temp->link=r;
         
         return 0;
    }
}

int display(struct node *q)
 {
     while(q!=NULL)
      {
          printf("%d ",q->data);
          q=q->link;
      }
      return 0;
 }
 
 int reverse(struct node **q)
  {
      struct node *temp,*r,*s;
      temp=*q;s=NULL;r=NULL;
      while(temp!=NULL)
       { 
         r=temp;
         temp=temp->link;
         r->link=s;
         s=r;
       }
       *q=r;
       return 0; 
      
  }
    

int main()
{
    struct node *p;
    p=NULL;
    
    add_node(&p,1);
    add_node(&p,2);
    add_node(&p,3);
    add_node(&p,4);
    add_node(&p,5);
    add_node(&p,6);
    add_node(&p,7);
    
    printf("\nbefore reversing the list  ");
    display(p);
    
    reverse(&p);
    
    printf("\nafter reversing the linked list   ");
    display(p);
    
    return 0;
    
    
    
}
