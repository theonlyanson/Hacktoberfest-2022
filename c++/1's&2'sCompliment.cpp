#include <iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
    int len=8;
    char bin[len],one[len],two[len];
    cout<<"Enter the Binary Number:";
    gets(bin);
    int flag =0;
    for(int i=0;i<len;i++)//one's compliment
    {
        if(bin[i]=='1')
        {
            one[i]='0';
        }
        else if(bin[i]=='0')
        {
            one[i]='1';
        }
        else
        {
            cout<<"Invalid Binary Digits";
            flag=1;
            return 0;
        }    
    }
    int carry=1;
    for(int i=len-1;i>=0;i--)//two's compliment
    {
        if(one[i]=='1' && carry==1)
        {
            two[i]='0';
        }
        else if(one[i]=='0' && carry==1)
        {
            two[i]='1';
            carry=0;
        }
        else
        {
            two[i]=one[i];
        }
    }
    if(flag==0)
    {
        cout<<"Binary number is:"<<bin<<endl;
        cout<<"1's Compliment of the number is:"<<one<<endl;
        cout<<"2's Compliment of the number is:"<<two<<endl;
    }

    return 0;
}