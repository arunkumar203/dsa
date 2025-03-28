#include <stdio.h>
int main()
{
    char st1[30],st2[30];
    int i,j;
    printf("enter your 1st string:");
    gets(st1);
    printf("enter your 2nd string:");
    gets(st2);
    i=0;
    while(st1[i]!=0)
    i++;
    j=0;
    while(st2[j]!=0)
    {
        st1[i]=st2[j];
        i++;
        j++;
    }
    st1[i]='\0';
    printf("%s",st1);
    return 0;


}