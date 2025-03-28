#include<stdio.h>
int main()

{
  FILE *fp;
  fp = fopen("sam.txt","w");
  fprintf(fp,"%s","samplearun");
  fclose(fp);
   return 0;
}
