#include <stdio.h>
#include <stdlib.h>
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
int dequeue()
{
    int x;
    struct node *t;
    if(front==0)
    printf("queue is empty!");
    else
    {
        x=front->data;
        t=front;
        
        front=front->next;
        free(t);
        
    }
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
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    

}


















