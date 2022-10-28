#include <stdio.h>
 
int main()
{
    int num, digit, sum =0;
    
    //Input a number
    printf("Enter a number to check for neon number: \n");
    scanf("%d",&num);
        
    //Calculate square of the input
    int square = num*num;
    
    //Sum the digits of the square
    while(square!=0){
        digit = square%10;
        sum += digit;
        square = square/10;
    }
    
    //Check if sum is equal to the input number
    if(sum == num)
        printf("Neon Number \n");
    else
        printf("Not a Neon Number \n");
 
    return 0;
}
