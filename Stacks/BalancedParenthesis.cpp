#include<bits/stdc++.h>
using namespace std;

checkifBalanced(string s)
{
    std::stack<char> ch;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            ch.push(s[i]);
        }
        else
        {
            if((s[i] == ')' && ch.top() == '(') || (s[i] == '}' && ch.top() == '{') || (s[i] == ']' && ch.top() == '['))
            {
                ch.pop();
            }
            else
            {
                cout << "Not balanced.";
            }
        }
    }
    if(ch.empty())
        cout << "Balanced";
    else
        cout << "Not Balanced.";
}
int main()
{
    string s="{()}[]";
    checkifBalanced(s);
    return 0;
}
