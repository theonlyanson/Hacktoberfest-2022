#include<iostream>
#include<string.h>
using namespace std;

void encryptyfunc()
{
    char text[100];
    char temp;
    int i, key;

    cout<<" Masukan kata yang akan dienkrpsi : ";cin>>text;
    cout<<" Masukan kata kunci : ";cin>>key;

    for (i=0; text[i] != '\0'; ++i){
        temp = text[i];
        if(temp >= 'a' && temp <= 'z')
        {
            temp = temp + key;
            if(temp > 'z'){
                temp = temp - 'z' + 'a' - 1;
            }
            text[i] = temp;
        }else if(temp >= 'A' && temp <= 'Z'){
            temp = temp - key;
            if(temp > 'Z'){
                temp = temp - 'Z' + 'A' - 1;
            }
            text[i] = temp;
        }
    }
    cout<<" Enkrisi kata : "<<text<<endl;
}

void decrypfunc()
{
     char text[100];
    char temp;
    int i, key;

    cout<<" Masukan kata yang akan dienkrpsi : ";cin>>text;
    cout<<" Masukan kata kunci : ";cin>>key;

    for (i=0; text[i] != '\0'; ++i){
        temp = text[i];
        if(temp >= 'a' && temp <= 'z')
        {
            temp = temp - key;
            if(temp > 'z'){
                temp = temp - 'z' - 'a' + 1;
            }
            text[i] = temp;
        }else if(temp >= 'A' && temp <= 'Z'){
            temp = temp - key;
            if(temp > 'Z'){
                temp = temp - 'Z' - 'A' + 1;
            }
            text[i] = temp;
        }
    }
    cout<<" Enkrisi kata : "<<text<<endl;
}
int main()
{
    int choose;

    cout<<" Masukan opsi dibawah ini !"<<endl;
    cout<<" ======================== "<<endl;
    cout<<" 1.enkrisi \t 2.deskripsi "<<endl;cin>>choose;

    switch(choose){
    case 1:
        encryptyfunc();
        break;
    case 2:
        decrypfunc();
        break;
    default:
        cout<<" tolong input yang bbenar !"<<endl;
        break;
    }

    return 0;
}
