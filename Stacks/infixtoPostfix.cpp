#include<bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
void infixtoPostfix(string infix)
{
    std::stack<char> st;
    for(int i=0; i<infix.size(); i++)
    {
        if((infix[i]>='a' && infix[i]<='z') ||(infix[i]>='A' && infix[i]<='Z'))
        {
            cout<<infix[i];
        }
        else if( infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(st.top() != '(')
            {
                cout << st.top();
                st.pop();
            }
                st.pop();
        }
        else
        {
            while(!st.empty() && prec(infix[i])<= prec(st.top()))
            {
                cout << st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    infixtoPostfix(infix);
}
