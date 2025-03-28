#include <stdio.h>
int main()
{
    long long int n1 = 0, n2 = 1;
    int i, n;
    int fibnum = n1 + n2;
    // printf("enter a number:");
    scanf("%d", &n);
    printf("%lld %lld ", n1, n2);
    for (i = 3; i <= n; i++)
    {
        printf("%lld ", fibnum);
        n1 = n2;
        n2 = fibnum;
        fibnum = n1 + n2;
    }
    return 0;
}
