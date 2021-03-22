#include<bits/stdc++.h>
using namespace std;

int evaluate(int a, int b, char c)
{
    switch(c){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;}
}

int precedence(char c)
{
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    return 0;
}
void evaluate(string s)
{
    std::stack<int> val;
    std::stack<char> oper;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
            continue;
        else if(isdigit(s[i]))
        {
            int temp = 0;
            while(i<s.size() && s[i]!=' ')
            {
                temp = temp*10 + (s[i] - '0');
                i++;
            }
            i--;
            val.push(temp);
        }
        else if(s[i] == '(')
                oper.push(s[i]);
        else if(s[i] == ')')
        {
            while(!oper.empty() && oper.top() != '(')
            {
                char op = oper.top(); oper.pop();
                int a = val.top(); val.pop();
                int b = val.top(); val.pop();
                int result = evaluate(b,a,op);
                val.push(result);
            }
            oper.pop();
        }
        else
        {
            while(!oper.empty() && precedence(oper.top()) >= precedence(s[i]))
            {
                char op = oper.top(); oper.pop();
                int a = val.top(); val.pop();
                int b = val.top(); val.pop();
                int result = evaluate(b,a,op);
                val.push(result);
            }
            oper.push(s[i]);
        }
    }
    while (!oper.empty())
    {
                char op = oper.top(); oper.pop();
                int a = val.top(); val.pop();
                int b = val.top(); val.pop();
                int result = evaluate(b,a,op);
                val.push(result);
    }
    cout << val.top();
}

int main()
{
    string expression = "100 * ( 2 + 12 ) / 14";
    evaluate(expression);
    return 0;
}
