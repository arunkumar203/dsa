#include <stdio.h>
int fun(int n);
int main()
{
    int n;
    printf("enter a number:");
    scanf("%d",&n);
    fun(n);

    return 0;
}
int fun(int n)
{
    int funval=0;
    if(n<2)
    {
        funval=(2*n*n)+(3*n)+4;
    }
    else if(n>2)
    {
        funval=(-2*n*n)+(3*n)-4;
    }
    else
    {
        funval=0;
    }
  printf("function value is %d",funval);
}

