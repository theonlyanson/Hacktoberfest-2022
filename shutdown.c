#include<stdio.h>
#include<stdlib.h>    

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn");

    char ch;
    
    printf("\nDo you want to shutdown your pc now (y/n)?");
    scanf("%c", &ch);

    if(ch == 'y'|| ch == 'Y')
    {  
        system("C:\\WINDOWS\\System32\\shutdown /s");
    }

    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}
