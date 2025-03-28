//inserting in a sorted ll
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first=0;
void create(int a[],int n)
{
    int i=0;
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=0;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=0;
        last->next=t;
        last=t;
    }
}
void  display(struct node *p)
{
    while(p)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
}
void sortinsert(struct node*p,int n)
{
    struct node*t,*q=0;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=n;
    int i=0;
  while(p->data < n)
 
  {
      q=p;
      p=p->next;
  }
  if(p==first)
  {
      t->next=first;
      first=t;
  }
  else{
  t->next = q->next;
  q->next=t;
  }
}

int main()
{
    struct node *temp;
    int a[]={3,5,7,9,12,15,17,20};
    create(a,8);
    display(first);
    sortinsert(first,2);
    display(first);
    
    
 
 
}