#include<stdio.h> 
int getReverse(int num, int rev){
    if(num == 0)
        return rev;
    
    int rem = num % 10;
    rev = rev * 10 + rem;
    
    return getReverse(num / 10, rev);
}

int main ()
{
    int num, reverse = 0;
    scanf("%d",&num);
    printf("The number is: %d\n",num);
        
    
    if (num == getReverse(num, reverse))
        printf("%d is Palindrome\n", num);
    else
        printf("%d is Not Palindrome\n", num);

}
