#include<stdio.h>

void insertlast(int x)
{
    node *t=new node;
    t->data=x;
    t->next=0;
    if(first==0)
    first=last=t;
    else
    {
        last->next=t;
        last=t;
    }
}
void display(struct node*p)
{
    while((!p) == 0)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
int main()
{
    insertlast(1);
    insertlast(4);
    insertlast(6);
    display(first);
    return 0;
}