#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*first=0,*second=0,*third=0;
void create(int a[],int n)
{
    int i;
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
/*void create2(int b[],int n)
{
    int i;
    struct node *t,*last;
    second=(struct node*)malloc(sizeof(struct node));
    second->data=b[0];
    second->next=0;
    last=second;
    for(i=0;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=b[i];
        t->next=0;
        last->next=t;
        last=t;
    }
}*/
void display(struct node*p)
{
    while((!p) == 0)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
}
int count(struct node *p)
{
    int c=0;
     while((!p) == 0)
     {
         c++;
         p=p->next;
     }
     printf("number of nodes is %d",c);
}
int add(struct node *p)
{
    int sum=0;
     while((!p) == 0)
     {
         sum=sum+ p->data;
         p=p->next;
     }
    printf("sum is %d",sum);

}
int max(struct node *p)
{
    int m=0;
    while((!p) == 0)
    {
        if(p->data > m)
        m=p->data;
        p=p->next;
    }
    printf("max is %d",m);

}
int search(struct node *p)
{
    int num=0;
    printf("enter the number that u want:");
    scanf("%d",&num);
    int n=0;
     while((!p) == 0)
     {
        if (num == p->data)
        {
            n++;
            p=p->next;
        }
     }
    if(n=0)
    printf("not found");
    else
    printf("found and number of times is %d",n);


}
void sortedinsert(struct node *p,int x)
{
    struct node *t,*q=0;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=0;
    if(first == 0)
    {
        first =t;
    }
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if (p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }

    }



}
int delete(struct node *p,int index)
{
    struct node *q=0;
    int x=-1,i;
    if(index==1)
    {
        p=first;
        x=first->data;
        first=first->next;
        free(q);

    }
    else
    {
        p=first;
         q=0;
        for(i=0;index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return 0;

    }

}
/*void issorted1(struct node *p)
{
    p=first;
    int i;
    struct node *q=0;
    q=p;
    p=p->next;

    for(i=0;i<5;i++)
    {
        q=p;
        p=p->next;
        if(p->data < q->data)
        break;
    }
    if(p->next = 0)
    printf("sorted");
    else
    printf("not sorted");

}*/
int issorted(struct node *p)
{
    int x=-65536;
    while((!p) == 0)
    {
        if(p->data < x )
        return 0;
        x=p->data;
        p=p->next;


    }
    return 1;

}
int removeduplicate(struct node *p)
{
    p=first;
  //struct node *q=p->next;
  struct node *q;
  q=p->next;
   
    while(p!= 0)
    {
        
        if((p->data)!= q->data)
        {
            p=q;
            q=q->next;

        }
        else
        {
            p->next = q->next;
            //delete(first,i);
            free(q);
            q=p->next;
        }
        
    }
    display(first);
    return 0;
    


}
void merge(struct node *p,struct node *q)
{
    struct node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=0;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=0;

    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=0;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=0;

        }
    }
    if(p)
    last->next=p;
    else
    last->next=q;
}
int isloop(struct node *f)
{
    struct node *p,*q;
    p=q=f;
    do
    {
        /* code */
        p=p->next;
        q=q->next;
        q=q?q->next:q;

    } while (/* condition */p && q && p!=q);
    if(p==q)
    printf("true");
    else
    printf("false");
    
}



int main()
{
   // struct node *t1,*t2;

    int a[]={10,20,30,40,50};
    //int b[]={12,32,45,55};
    
   create(a,4);
   display(first);
    delete(first,1);
    display(first);
    // create(b,4);
    // delete(second,1);
    // display(second);
    // merge(first,second);
    // display(third);
    






    //count(first);//
    //add(first );
    //max(first);
    //search(first);
   //sortedinsert(first,12);
  // display(first);


    /*if(issorted(first))
    printf("sorted");
    else
    printf("\n not sorted");*/

   // removeduplicate(first);
   // t1=first->next->next;
    //t2=first->next->next->next->next;
    //t2->next=t1;
    //printf("/n%d\n",isloop(first));

    
    
    






    return 0;
}
