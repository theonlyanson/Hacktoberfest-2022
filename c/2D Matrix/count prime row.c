//Code

#include<stdio.h>
#include<math.h>
#define ROW 10
#define COLUMN 10
void readMatrix(int [ROW][COLUMN],int ,int);
void displayMatrix(int [ROW][COLUMN],int ,int);
void countprimes(int [ROW][COLUMN],int ,int);
int primecount1Darray(int [],int);
int isprime(int);
int main()
{
int a[ROW][COLUMN];
int r,c;
printf("Enter rows and columns:\n");
scanf("%d%d",&r,&c);
printf("Enter array elements:\n");
readMatrix(a,r,c);
printf("Array is:\n");
displayMatrix(a,r,c);
countprimes(a,r,c);
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
void countprimes(int a[ROW][COLUMN],int r,int c)
{
int i,p;
for(i=0;i<r;i++)
{
p=primecount1Darray(a[i],c);
printf("number of prime in %dth row=%d\n",i,p);
}
}
int primecount1Darray(int b[],int n)
{
int i,p,count=0;
for(i=0;i<n;i++)
{
if(b[i]<=1)
continue;
p=isprime(b[i]);
if(p==1)
count++;
}
return count;
}
int isprime(int n)
{
int i;
for(i=2;i<=sqrt(n);i++)
{
if(n%i==0)
return 0;
}
return 1;
}


///Print
/*
Enter rows and columns:
3 3
Enter array elements:
5
6
3
2
4
8
9
6
5
Array is:
5 6 3
2 4 8
9 6 5
number of prime in 0th row=2
number of prime in 1th row=1
number of prime in 2th row=1
