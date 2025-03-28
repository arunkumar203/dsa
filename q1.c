#include<stdio.h>
int main()
{
    int n,revnum=0;
    printf("enter your num:");
    scanf("%d",&n);
    while(n!=0)
    {
  
    revnum=revnum*10+n%10;
    n=n/10;
    }
    printf("number is %d",revnum);
    return 0;
}