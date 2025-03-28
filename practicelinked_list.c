#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*first=0;
void create(int a[],int n)
{
    int i;
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=0;
    last=first;
    for(i=0;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=0;
        last->next=t;
        last=t;
    }
}
void display(struct node *p)
{
 while(p!=NULL)
    {
       printf("%d",p->data);
       p = p->next;
    }
}
int main()
{
    struct Node *temp;
   int a[]={1,4,3,6,9,7};
    create(a,6);
    return 0;
}