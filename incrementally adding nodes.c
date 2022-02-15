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
     r=malloc(sizeof(struct node));
     r->data=num;
     
     if(*q==NULL)
      {
          r->link=NULL;
          *q=r;
          return 0;
      }
      else if(temp->data>num)
      { r->link=temp;
        *q=r;
        return 0;
          
      }
      else
      {
          temp=*q;
          
          while(temp!=NULL)
          {
         
            if(temp->data<=num&& temp->link==NULL||(temp->link)->data>num)
             { 
               r->link=temp->link;
               temp->link=r;
               return 0;
             }
             temp=temp->link;
           }
       }
 }
 
 int display(struct node *q)
  {  
  
      while( q!=NULL)
       { printf(" %d",q->data);
          q=q->link;
           
       }
       return 0;
  }

int main()
{
    // adding the nodes into the linked list in ascending order.
    struct node *p;
    p=NULL;
    
    
    add_node(&p,2);
    add_node(&p,3);
    add_node(&p,1);
    add_node(&p,5);
    add_node(&p,7);
    add_node(&p,11);
    add_node(&p,4);
    add_node(&p,3);
    add_node(&p,6);
    add_node(&p,9);
    
    display(p);
}

