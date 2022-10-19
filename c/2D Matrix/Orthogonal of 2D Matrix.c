#include<stdio.h>
#define ROW 10
#define COL 10
void readMatrix(int [ROW][COL],int ,int);
void displayMatrix(int [ROW][COL],int ,int);
void transposeMatrix(int a[ROW][COL],int r,int c, int b[ROW][COL]);
void matrixmultiplication(int a[ROW][COL],int R1,int C1,int b[ROW][COL], int res[ROW][COL]);
int identityMatrix(int a[ROW][COL],int r,int c);
main()
{
int r,c,i;
int a[ROW][COL];
int b[ROW][COL];
int res[ROW][COL]={0};
printf("Enter the order of matrix: ");
scanf("%d%d",&r,&c);
printf("\nEnter the elements of matrix:\n");
readMatrix(a,r,c);
transposeMatrix(a,r,c,b);
matrixmultiplication(a,r,c,b,res);
i=identityMatrix(res,r,r);
if(i==1)
printf("\nIt is orthogonal matrix");
else
printf("\nNot orthogonal matrix");
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
void transposeMatrix(int a[ROW][COL],int r,int c, int b[ROW][COL])
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
b[j][i]=a[i][j];
}
}
}
void matrixmultiplication(int a[ROW][COL],int r,int c,int b[ROW][COL], int res[ROW][COL])
{
int i,j,k;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
for(k=0;k<c;k++)
{
res[i][j]=res[i][j]+a[i][k]*b[k][j];
}
}
}
}
int identityMatrix(int a[ROW][COL],int r,int c)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if(i==j && a[i][j]!=1)
return 0;
if(i!=j && a[i][j]!=0)
return 0;
}
}
return 1;
}
