#include<stdio.h>
#include<stdlib.h>

void display(int a[],int size)
{ int i;
  printf("\n");
  for(i=0;i<size;i++)
  printf("%d ",a[i]);
  
  printf("\n");
  
}

void bSort(int a[],int size)
{ int i,j,n=size-1,temp;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		n--;
		display(a,size);
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
  bSort(a,size);
  display(a,size);
  return 0;
  	
}
