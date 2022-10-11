#include<stdio.h>  
int main()    
{    
int n,d,s=0,temp;    
printf("Enter a number=\n");    
scanf("%d",&n);    
temp=n;    
while(n>0)    
{    
d=n%10;    
s=s+(d*d*d);    
n=n/10;    
}    
if(temp==s)    
printf("Number is an Armstrong number\n");    
else    
printf("Number is not an Armstrong number\n");    
return 0;  
}   