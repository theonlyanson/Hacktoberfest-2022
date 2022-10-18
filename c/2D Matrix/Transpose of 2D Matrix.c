#include<stdio.h>
#define ROW 10
#define COL 10
void ReadArray(int [ROW][COL], int, int);
void DisplayArray(int [ROW][COL], int, int);
void trans(int [ROW][COL],int [ROW][COL],int ,int) ;
main()
{
int r,c,sum;
int a[ROW][COL];
int b[ROW][COL];
printf("Enter the order of 2D matrix: ");
scanf("%d%d",&amp;r,&amp;c);
printf("\nEnter the Elements of Matix:\n");
ReadArray(a,r,c);
printf("\nThe Elements of Matix are\n");
DisplayArray(a,r,c);
trans(a,b,r,c);
}
void ReadArray(int a[ROW][COL], int r, int c)
{
int i,j;
for(i=0;i&lt;r;i++)
{
for(j=0;j&lt;c;j++)
{
scanf("%d",&amp;a[i][j]);
}
}
}
void DisplayArray(int a[ROW][COL], int r, int c)
{
int i,j;
for(i=0;i&lt;r;i++)
{
for(j=0;j&lt;c;j++)
{
printf("\t%d",a[i][j]);
}
printf("\n");
}
}
void trans(int a[ROW][COL], int b[ROW][COL], int r, int c)
{
int i,j ;
printf("Transpose of matrix: \n");
for (i=0;i&lt;r;i++)
{
for (j=0;j&lt;c;j++)
{
b[i][j]=a[j][i];
printf("\t%d",a[j][i]);
}printf("\n");
}
}
