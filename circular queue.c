#include<stdio.h>
#include<stdlib.h>
int f=0;
int r=0;
int size;
int a[20]={0};
void enqueue(int x)
{
    if((r+1)%size==f)
    printf("full!\n");
    else
    {
        r=(r+1)%size;
        a[r]=x;
        
    }
}
void dequeue()
{
    if(f==r)
    printf("empty!");
    else
    {
        f=(f+1)%size;
        int x=a[f+1];
        // a[f+1]=0;
        printf("dequed is %d\n",x);
        
    }
}
void display()
{
   int  j=f+1;
    do
 {
 
 printf("%d ",a[j]);
 j=(j+1)%size;
 }while(j!=(r+1)%size);
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








