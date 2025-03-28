#include<stdio.h>
#include<stdlib.h>
int main()
{
     char str[20];
     int i=0;
     int m=0;
  
printf("Enter a string: ");
scanf("%s",str);
while(str[i]!=0)
{
if(str[i]==str[i+1])
{
i++;
m++; 
}
            
 else
 {
printf("%c%d",str[i],m+1);
i++;
m=0;
}
            
    
        
}
return 0;
}