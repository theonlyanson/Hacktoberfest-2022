#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int number, input, guesses = 1;
    srand(time(0));
    number = (rand() % 100) + 1; // generate random number between 1 and 100
                                 // keep running the loop until player guess the number
    do
    {
        printf("GUESS THE NUMBER\n");
        scanf("%d", &input);
        if (input < number)
        {
            printf("LOWER THAN NUMBER\n");
        }
        else if (input > number)
        {
            printf("HIGHER THAN NUMBER\n");
        }
        else
        {
            printf("CONGO!!!\nYOU GUESSED IT RIGHT");
            printf("\nyou guessed in %d attempts", guesses);
        }
        guesses++;
    } while (input != number);

    return 0;
}