//A game of Rock,Paper,Scissors using C language.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int grn(int n)
{
    srand(time(NULL));
    return rand()%n;
}
int greater(char c1,char c2)
{
//  Here 'r'=ROCK,'s'=Scissor,'p'=Paper
     if (c1==c2)
     {
         return -1;
     } 
    if ((c1=='r')&&(c2=='s'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    if ((c1=='p')&&(c2=='r'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    if ((c1=='s')&&(c2=='p'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main() 
{  
    int ps=0,cs=0,temp;
    char plc,cc;
    char dict[]={'r','p','s'};
    printf("Welcome to (ROCK,PAPER,SCISSOR) game.\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Player's Turn:\n");
        printf("Choose (1 for Rock(r) , 2 for Paper(p) , 3 for Scissors(s)):");
        scanf("%d",&temp);
        plc=dict[temp-1];
        printf("\nYou choose %c",plc);

        printf("\nComputers turn:");
        temp=grn(3)+1;
        cc=dict[temp-1];
        printf("\nComputer choose=%c\n",cc);
        if (greater(cc,plc)==1)
        {
            cs+=1;
        }
        else if (greater(cc,plc)==-1)
        {
            cs+=1;
            ps+=1;
        }
        else
        {
            ps+=1;
        }
    }
    printf("\n******Results******\n");
    if (ps>cs)
    {
        printf("\nWow!!! You Win the game\n");
    }
    else if (ps<cs)
    {
        printf("\nOhoo!!! You Lose the Game\n");
    }
    else
    {
        printf("\nIts a Tie\n");
    }
    return 0;
}
