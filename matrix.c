#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int b;

int creatematrix(int a)
{
    printf("enter elements\n");
    int array[a][b];
    for(int i=0;i<a;i++)
    {
        int j;
        for(j=0;j<b;j++)
        {
            int key1;
            scanf("%d",&key1);
            array[i][j]=key1;
        }
    }
      presentmatrix(array,a);
}


int presentmatrix(int array[][b],int a)
{
    
    int i,j;
    for( i=0;i<a;i++)
    {
        
        for(j=0;j<b;j++)
        {
            int key=array[i][j];
           
            printf("%d ",key);
          
        }
        printf("\n");
    }


}



void main()
{
    int a;
    printf("enter the dimansion of matrix\n");
    scanf("%d",&a);
   
    scanf("%d",&b);
    
    creatematrix(a);
}