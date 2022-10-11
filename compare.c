#include <stdio.h>
main() 
{
  int a, b, c;
  printf("Please enter the value of a, b and c: ");
  scanf("%d%d%d",&a, &b, &c);
  if (a > b && a > c) 
  {
    printf("%d is greater.", a);
  }
  else if (b > c) 
  {
    printf("%d is greater.", b);
  }
  else
  {
    printf("%d is greater.", c);
  }
} 
