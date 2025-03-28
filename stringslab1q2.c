#include<stdio.h>

int main()
{
    char st1[30],st2[30];
    int i,j=0;
    printf("enter your string 1:");
    gets(st1);
    printf("enter your string 2:");
    gets(st2);
    while(st1[i]!='\0'|| st2[i]!='\0')
    {
        if(st1[i]!=st2[i])
        {
            j=1;
            break;
        }
        i++;
    }
    if(j==1)
    printf("not equal");
    else 
    printf("equal");
    
    return 0;
}