#include<stdio.h>
#include<stdlib.h>
int f=-1;
int r=-1;
int size;
int a[20]={0};
void enqueue(int x)
{
    if(r==size-1)
    printf("full!\n");
    else
    {
        a[r+1]=x;
        r++;
    }
}
void dequeue()
{
    if(f==r)
    printf("empty!");
    else
    {
        int x=a[f+1];
        a[f+1]=0;
        printf("dequed is %d\n",x);
        f++;
    }
}
void display()
{
    for(int j=f+1;j<r+1;j++)
    {
        printf("%d ",a[j]);
    }
    printf("\n");
}
int main()
{
    printf("enter size:");
    scanf("%d",&size);
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    display();
    return 0;
}








