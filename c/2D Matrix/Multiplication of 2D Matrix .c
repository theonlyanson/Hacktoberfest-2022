#include<stdio.h>
#include<math.h>
#define ROW 10
#define COLUMN 10
void readMatrix(int [ROW][COLUMN],int ,int);
void displayMatrix(int [ROW][COLUMN],int ,int);
void matrixmultiplication(int a[ROW][COLUMN],int R1,int C1,int[ROW][COLUMN],int R2, int C2, int res[ROW][COLUMN]);
int main()
{
int a[ROW][COLUMN];
int b[ROW][COLUMN];
int res[ROW][COLUMN]={0};
int R1,C1,R2,C2;
printf("Enter order of 1st matrix:\n");
scanf("%d%d",&R1,&C1);
printf("Enter order of 2nd matrix:\n");
scanf("%d%d",&R2,&C2);
if(C1!=R2)
{
printf("Matrix multiplication not possible\n");
exit(0);
}
printf("Enter elements of 1st Matrix:\n");
readMatrix(a,R1,C1);
printf("Enter elements of 2nd matrix:\n");
readMatrix(b,R2,C2);
matrixmultiplication(a,R1,C1,b,R2,C2,res);
printf("Matrix Array after multiplication:\n");
displayMatrix(res,R1,C2);
return 0;
}
void readMatrix(int a[ROW][COLUMN],int r,int c)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
scanf("%d",&a[i][j]);
}
}
void displayMatrix(int a[ROW][COLUMN],int r,int c)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
}
void matrixmultiplication(int a[ROW][COLUMN],int R1,int C1,int b[ROW][COLUMN],int R2, int C2, int res[ROW][COLUMN])
{
int i,j,k;
for(i=0;i<R1;i++)
{
for(j=0;j<C2;j++)
{
for(k=0;k<C1;k++)
{
res[i][j]=res[i][j]+a[i][k]*b[k][j];
}
}
}
}
