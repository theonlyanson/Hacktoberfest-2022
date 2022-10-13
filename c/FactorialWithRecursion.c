#include<stdio.h>
int fact(int);
int main()
{
int n;
printf("Enter an integer: ");
scanf("%d",&n);
if(n<0)
{
printf("Factorial of does not exist\n");
}
else
{
printf("Factorial=%d \n",fact(n));
}
return 0;
}


int fact(int i)
{
if (i==0)
return 1;

else
return i*fact(i-1);
}
