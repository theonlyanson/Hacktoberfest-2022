
#include<stdio.h>
#include<stdlib.h>

void display(int a[],int size)
{ int i;
  printf("The given array is\n");
  for(i=0;i<size;i++)
  printf("%d ",a[i]);
  
  printf("\n");
  
}
void lsearch(int key,int a[],int size)
{  int i,cnt=0;
  for(i=0;i<size;i++)
  { 
    if(a[i]==key)
    {
	printf("%d ,%d \n",i,a[i]);
	cnt++;
    }
  }
  if(cnt==0)
  printf("Element not found\n");
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
  printf("Enter the element you want to search\n");
  scanf("%d",&key);
  lsearch(key,a,size);
  return 0;
  	
}
