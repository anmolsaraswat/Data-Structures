#include<bits/stdc++.h>
using namespace std;

postfixToInfix(string postfix)
{
    std::stack<string> s;
    string a, b, temp;
    for(int i=0;i<postfix.size();i++)
    {
        if((postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z'))
            s.push(string(1,postfix[i]));
        else
        {
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            temp = "(" + b + postfix[i] + a + ")";
            s.push(temp);
        }
    }
    cout << s.top();
}

int main()
{
    string postfix = "ab*c+";
    postfixToInfix(postfix);
    return 0;
}
