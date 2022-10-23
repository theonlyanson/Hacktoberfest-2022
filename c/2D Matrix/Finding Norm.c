//Code

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void read(int A[10][10],int m,int n);
void display(int A[10][10],int m,int n);
float calnorm(int A[10][10],int m,int n);
main()
{
int A[10][10],i,j,m,n;
float norm=0;
printf("Enter order of the matrix\n");
scanf("%d%d",&m,&n);
if(m!=n)
{
printf("Invalid size of the matrix\n");
exit(0);
}
printf("Enter elements of the matrix\n");
read(A,m,n);
printf("Entered matrix is:\n");
display(A,m,n);
norm=calnorm(A,m,n);
printf("Norm of the given matrix is=%f\n",norm);
}
void read(int A[10][10],int m,int n)
{
int i,j;

for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%d",&A[i][j]);
}

void display(int A[10][10],int m,int n)
{
int i,j;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
printf("%d\t",A[i][j]);

printf("\n");
}
return;
}
float calnorm(int A[10][10],int m,int n)
{
int i,j,sum=0;
float norm;

for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
sum=sum+A[i][j]*A[i][j];
}
norm=sqrt(sum);
return(norm);
}

//OUTPUT
/*
Enter order of the matrix
3 3
Enter elements of the matrix
6
5
3
2
1
5
9
6
4
Entered matrix is:
6 5 3
2 1 5
9 6 4
Norm of the given matrix is=15.264338

Process returned 0 (0x0) execution time : 10.820 s
Press any key to continue.
