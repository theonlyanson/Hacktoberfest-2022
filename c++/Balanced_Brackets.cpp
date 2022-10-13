#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isBalanced(string s)
{
    if (s.size() == 0)
    {
        return true;
    }
    stack<char> str;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i]=='[' || s[i]=='{')
        {
            str.push(s[i]);
        }
        else
        {
            if (str.size() == 0)
            {
                return false;
            }
            if(str.top()=='(' && s[i]==')'){
                str.pop();
            }
            else if(str.top()=='[' && s[i]==']'){
                str.pop();
            }
            else if(str.top()=='{' && s[i]=='}'){
                str.pop();
            }
            else{
                return false;
            }
        }
    }
    if (str.size() == 0)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
    string s;
    cin >> s;
    cout << ((isBalanced(s)) ? "YES" : "NO")<<endl;
    }
}
