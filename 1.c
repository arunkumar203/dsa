#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
   
    for(int k=0;k<n;k++)
    {
        k=k*k*k*k;
        if(k==n)
        {

            printf("true");
            break;
        }


    }
    if(k==n-1)
        printf("false");
}