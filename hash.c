#include <stdio.h>


int main ()
{
  int n;

  int i = 0;
  printf ("Hello World\n");
  printf ("enter size of array:");
  scanf ("%d", &n);
  int a[n];
  int c[n];
  printf ("enter all elements of array:");
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  int max = a[0];
  for (i = 0; i < n; i++)
    {

      if (a[i] > max)
	max = a[i];
    }
  printf ("max element is %d\n", max);
  int b[500] = { 0 };
  for (i = 0; i < n; i++)
    {
      b[a[i]]++;
    }
  int j = 0;

  for (i=0,j = 0; j < max+1;i++, j++)
    {
    if(b[j]>0)
    {
    c[i]=j;
      printf("%d\n",c[i]);
    }
    }



  return 0;
}