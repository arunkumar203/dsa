#include <stdio.h>
#include<stdlib.h>
int f=-1;;
int r=-1;
int size=20;
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
int  dequeue()
{
    int x=0;
    if(f==r)
    printf("empty!");
    else
    {
         x=a[f+1];
        a[f+1]=0;
        // printf("dequed is %d\n",x);
        f++;
    }
    return x;
    
}

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
void create()
{
    int x;
    struct node *p,*t;
    printf("enter root value:");
    scanf("%d",&x);
    root=(struct node *)malloc(sizeof(struct node));
    
    root->data=x;
    root->left=root->right=NULL;
    enqueue(root->data);
    while(f>r)
    {
        int l=dequeue();
        p->data=l;
        printf("enter left child of %d",p->data);
        scanf("%d",&x);
        if(x>0)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->left=t->right=NULL;
            p->left=t;
            enqueue(x);
        }
        printf("enter right child of %d",p->data);
        scanf("%d",&x);
         if(x>0)
         {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->left=t->right=NULL;
            p->left=t;
            enqueue(x);
        }
        
    }
}
void preorder(struct node *p)
{
 if(p)
 {
 printf("%d ",p->data);
 preorder(p->left);
 preorder(p->right);
 }
}
int main()
{
    

    create();
    preorder(root);
    return 0;
}







