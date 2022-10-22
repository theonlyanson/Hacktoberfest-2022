C
#include <stdio.h>

#include <conio.h>

#include <string.h>

void main(){

   char string[20],temp;

   int i,length;

   printf("Enter String : ");

   scanf("%s",string);

   length=strlen(string)-1;

   for(i=0;i<strlen(string)/2;i++){

      temp=string[i];

      string[i]=string[length];

      string[length--]=temp;

   }

   printf("\nReverse string :%s",string);

   getch();

}
