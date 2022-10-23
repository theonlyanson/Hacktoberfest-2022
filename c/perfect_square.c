#include<stdio.h>
int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    int i, number;
    printf("Enter a number: ");
    scanf("%d", &number);
    for(i = 0; i <= number; i++)
    {
        if(number == i*i)
        {
            printf("\n\n\n\t\t\t%d is a perfect square\n\n\n", number);
            printf("\n\n\t\t\tCoding is Fun !\n\n\n");
            return 0;   // same as using break in this case to end the program
        }
    }
    printf("\n\n\n\t\t\t%d is not a perfect square\n", number);
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}
