
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
 char data;
 struct node *next;
}*top=0;
void push(char x)
{
 struct node *t;
 t=(struct node*)malloc(sizeof(struct node));
 
 if(t==0)
 printf("stack is full\n");
 else
 {
 t->data=x;
 t->next=top;
 top=t;
 }
 
}
char pop()
{
 struct node *t;
 char x=-1;
 
 if(top==0)
 printf("Stack is Empty\n");
 else
 {
 t=top;
 top=top->next;
 x=t->data;
 free(t);
 }
 return x;
}
void display()
{
 struct node *p;
 p=top;
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
 printf("\n");
}
int isbal(char *exp)
{
 int i;
 
 for(i=0;exp[i]!='\0';i++)
 {
 if(exp[i]=='(')
 push(exp[i]);
 else if(exp[i]==')')
 {
 if(top==0)
 return 0;
 pop();
 }
 }
 if(top==0)
 return 1;
 else
 return 0;
}
int pre(char x)
{
 if(x=='+' || x=='-')
 return 1;
 else if(x=='*' || x=='/')
 return 2;
 return 0;
}
int isoperand(char x)
{
 if(x=='+' || x=='-' || x=='*' || x=='/')
 return 0;
 else
 return 1;
 
}
char * intoPost(char *infix)
{
 int i=0,j=0;
 char *postfix;
 int len=strlen(infix);
 postfix=(char *)malloc((len+2)*sizeof(char));
 
 while(infix[i]!='\0')
 {
 if(isoperand(infix[i]))
 postfix[j++]=infix[i++];
 else
 {
 if(pre(infix[i])>pre(top->data))
 push(infix[i++]);
 else
 {
 postfix[j++]=pop();
 }
 }
 }
 while(top!=NULL)
 postfix[j++]=pop();
 postfix[j]='\0';
 return postfix;
}

int main()
{
 char *exp="((a+b)*(c-d))";
 
 printf("%d ",isbal(exp));
 
 return 0;
}