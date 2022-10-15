#include<stdio.h>
#include<stdlib.h>

void display(int a[],int size)
{ int i;
  printf("The given array is\n");
  for(i=0;i<size;i++)
  printf("%d ",a[i]);
  
  printf("\n");
  
}

void ISort(int a[],int size)
{ 
	int i,j,key;
	for(i=1;i<size;i++)
	{
		j=i-1; key=a[i];
		
		while(key<a[j]&&j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
int main()
{ int size,i,key;
  printf("Enter the size of the array\n");
  scanf("%d",&size);
  int a[size];
  printf("Enter the elements of the array\n");
  for(i=0;i<size;i++)
  scanf("%d",&a[i]);
  display(a,size);
  ISort(a,size);
  display(a,size);
  return 0;
}
