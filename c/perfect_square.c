#include <stdio.h>
#include <math.h>
int main()
{
int num;
int num2;
float sq;
printf("Enter an integer number: ");
scanf("%d",&num);
sq=sqrt((double)num);
num2=sq;
if(num2==sq)
printf("%d is a perfect square.",num);
else
printf("%d is not a perfect square.",num);
return 0;
}
