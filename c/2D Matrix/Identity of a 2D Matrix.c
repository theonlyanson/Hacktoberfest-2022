#include<stdio.h>
#define ROW 10
#define COL 10
void readMatrix(int [ROW][COL],int ,int);
void displayMatrix(int [ROW][COL],int ,int);
int identityMatrix(int a[ROW][COL],int r,int c);
main()
{
int r,c,i;
int a[ROW][COL];
int b[ROW][COL];
int res[ROW][COL]={0};
printf("Enter the order of matrix: ");
scanf("%d%d",&r,&c);
printf("\nEnter the Elements of matrix:\n");
readMatrix(a,r,c);
printf("\nThe Given matrix is :\n");
displayMatrix(a,r,c);
i=identityMatrix(res,r,c);
if(i==1)
printf("\nIt is Identity matrix");
else
printf("\nNot Identity matrix");

}

void readMatrix(int a[ROW][COL],int r ,int c)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
scanf("%d",&a[i][j]);
}
}
void displayMatrix(int a[ROW][COL],int r,int c)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
printf("%d\t",a[i][j]);
printf("\n");
}
}

int identityMatrix(int a[ROW][COL],int r,int c)
{
int i,j,flag=1;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if(i==j && a[i][j]!=1)
flag=0;
else if(i!=j && a[i][j]!=0)
flag=0;

}
}
return flag;
}
