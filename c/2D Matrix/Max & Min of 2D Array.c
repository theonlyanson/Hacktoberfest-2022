#include<stdio.h>
#define ROW 10
#define COL 10

void ReadArray(int [ROW][COL], int, int);
void DisplayArray(int [ROW][COL], int, int);
void SumEachRow(int [ROW][COL], int, int);
void SumEachCol(int [ROW][COL], int, int);
void MinMaxArray(int [ROW][COL], int, int);
main()
{
int r,c,sum;
int a[ROW][COL];
double avg;
printf("Enter the order of 2D matrix: ");
scanf("%d%d",&r,&c);
printf("\nEnter the Elements of Matix:\n");
ReadArray(a,r,c);
printf("\nThe Elements of Matix are\n");
DisplayArray(a,r,c);
MinMaxArray(a,r,c);
}

void ReadArray(int a[ROW][COL], int r, int c)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
scanf("%d",&a[i][j]);
}
}
}

void DisplayArray(int a[ROW][COL], int r, int c)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
}

void MinMaxArray(int a[ROW][COL], int r, int c)
{
int i,j,min=a[0][0] ,max=a[0][0];
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if (a[i][j] > max)
{
max = a[i][j];
}
if (a[i][j] < min)
{
min = a[i][j];
}
}
}
printf("Min is: %d\n",min);
printf("Max is: %d\n",max);
}
