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
void insert(struct node*p,int index,int n)
{
    struct node*t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=n;
    int i=0;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++)
        p=p->next;
        t->next=p->next;
        p->next=t;
        
    }
}
int main()
{
    struct node *temp;
    int a[]={3,5,7,10,25,8,32,2};
    create(a,8);
    insert(first,0,3);
    display(first);
 
 display(first);
}