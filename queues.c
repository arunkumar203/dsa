#include <stdio.h>
#include <stdlib.h>
int size;
// int m=0;
struct node 
{
    int data;
    struct node *next;
}*front =0,*rear=0;
void enqueue(int x)
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=0;
    if(front==0)
    front =rear=t;
    else
    {
        rear->next=t;
        rear=t;
        
    }
}
int  mini()
{
    struct node *p=front;
    int m=0;
    while(p)
    {
        if(p->data>m)
        m=p->data;
        p=p->next;
    }
    printf("min is %d",m);
    return m;
    
    


}
void dequeue()
{
    
    
    // struct node *q=0;
    struct node *p=front;
    int m=mini();
    printf("min is %d",m);
    while(p->data!=m)
    p=p->next;
    p=p->next;
    free(p);
}

void display()
{
   struct node *p=front;
   while(p)
        {
            printf("%d ",p->data);
            p=p->next;
        }
 printf("\n");
}
int main()
{
    int k;
   printf("enter size:");
   scanf("%d",&size);
   printf("enter elements for element priority:");
   for(int i=0;i<size;i++)
   {
       scanf("%d",&k);
        enqueue(k);
   }
   display();
   dequeue();
   display();

}


















