#include<stdio.h>
#include<stdlib.h>
int top=-1;
int size;
int a[20]={0};
// void create()

void display()
{
    for(int j=0;j<=top;j++)
    printf("%d ",a[j]);
    
}
void push(int x)
{
    if(top==size-1)
    printf("stack overflow!\n");
    else
    {
        a[top+1]=x;
        top++;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("underflow!");
    }
    else{
   int  x=a[top];
   a[top]=0;
    top--;
    printf("\n");
    return x;
    }
}
int main()
{
    // create();
    printf("enter size:");
    scanf("%d",&size);
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    
    
    display();
    printf("popped is %d\n",pop());
    display();
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
