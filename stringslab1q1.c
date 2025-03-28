#include<stdio.h>
int main()
{
    char st[30];
    int i,l=0;
    printf("enter your string:");
    gets(st);
    for(i=0;st[i] !='\0';i++)
    l++;
    printf("%d",l);
    return 0;
}