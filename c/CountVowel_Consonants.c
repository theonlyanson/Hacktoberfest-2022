#include <stdio.h>
#include <string.h>
int main()
{
	char str[100];
	int i,j,len=0, vowel =0, consonant= 0;
	printf("C program to count vowels and consonants \n");
	printf("Please enter a string : ");
	scanf("%[^\n]", str);
	len=strlen(str);
	for(i=0; i<len; i++)
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
		{
			vowel++;
		}else if((str[i]>=65 && str[i]<=90)|| (str[i]>=97 && str[i]<=122)){
		    consonant++;
		}
	}
	printf("Total number of vowels are : %d and Consonants are : %d",vowel,consonant);
    return 0;
}
