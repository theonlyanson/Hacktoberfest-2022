#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n][3],i,j,s=0,c=0;
for(i=0;i<n;i++)
{
for(j=0;j<3;j++)
{
cin>>a[i][j];	
}	
}
for(j=0;j<3;j++)
{
	for(i=0;i<n;i++)
	{
	s=s+a[i][j];	
	}
	if(s==0)
	c++;
}
if(c==3)
cout<<"YES";
else
cout<<"NO";	
}
