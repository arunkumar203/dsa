

#include <stdio.h>

int main()
{
    printf("Hello World!\n");
    int i,j,m,n,k;
    printf("enter a number for elements in array:\n");
    scanf("%d",&i);
    j=i;
    n=i;
    k=i;
    int a[i];
    int b[j];
    for(m=0;m<i;m++)
    {
        printf("enter %dth element:\n",m);
        scanf("%d",&a[m]);
        printf("entered number is %d\n",a[m]);
    }
    for(m=0;m<i;m++)
    {
        b[n-1]=a[m];
        n--;
        
    }
    for(m=0;m<i;m++)
    {
        printf("%dth element:",m,b[m]);
    }
    
    

    return 0;
}
