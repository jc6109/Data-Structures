#include<stdio.h>
#include<stdlib.h>



struct node
{
    int data;
    struct node*link;
};

int add_at_end(struct node **q,int num )
{
  struct node *temp,*r;
  temp=*q;
 if(*q==NULL)
  {
      temp= malloc(sizeof(struct node));
      temp->data=num;
      temp->link=NULL;
      *q=temp;
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

  }
  return 0;

}

int add_at_start(struct node **q,int num)
 {
     struct node *temp,*r;
     temp=*q;
     r=malloc(sizeof(struct node));
     r->data=num;
     r->link=temp;
     *q=r;
     return 0;
 }

 int add_at_index(struct node **q,int num,int index)
 {  int position=1;
     struct node *temp,*r;
     temp=*q;
     r=malloc(sizeof(struct node));
     r->data=num;

     if(index==1)
      {r->link=temp;
      *q=r;

      }
      else
      {
          while(temp->link!=NULL && position<index-1)
         {
          temp=temp->link;
          position++;
         }
      
         r->link=temp->link;
         temp->link=r;

      }

      return 0;

    
 }

 int del_at_index(struct node**q,int index)
 {
     int i;
     struct node *temp,*old;
     temp=*q;
     if(*q==NULL)
      {
          printf("\n no element in linked list.");
          
      }
      else if(index==1)
      {
          *q=temp->link;
          temp->link=NULL;

          return temp->data;
      }

      else
      { for(i=1;i<index;i++)
         {
             old=temp;
             temp=temp->link;
              if(temp==NULL)
               {
                   printf("\nindex not found.");
                   return NULL;
               }
         }

         old->link=temp->link;
         temp->link=NULL;

         return temp->data;

      }

 }

int display(struct node *q)
 {
     while(q!=NULL)
      {
          printf(" %d",q->data);
          q=q->link;
      }
      return 0;
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

  printf("\nadd at end\n");
  display(p);

  add_at_start(&p,10);
  add_at_start(&p,9);
  add_at_start(&p,8);
  add_at_start(&p,7);
  
  printf("\nadd at start\n");
  display(p);

  add_at_index(&p,11,3);
  add_at_index(&p,12,5);
  add_at_index(&p,13,7);
  add_at_index(&p,14,1);
  add_at_index(&p,15,9);
  add_at_index(&p,11,11); 

  printf("\nadd at index\n");
  display(p);
   
   int data;

  data=del_at_index(&p,1);
  printf("\n%d is deleted",data);
  data=del_at_index(&p,5);
  printf("\n%d is deleted",data);
  data=del_at_index(&p,17);
  printf("\n%d is deleted",data);
  data=del_at_index(&p,23);
  printf("\n%d is deleted",data);
  data=del_at_index(&p,11);
  printf("\n%d is deleted",data);

  printf("\ndelete  at index\n");
  display(p);



  

  return 0;


}
