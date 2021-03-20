#include<bits/stdc++.h>
using namespace std;

prefixtoInfix(string postfix)
{
    std::stack<string> st;
    string tempa, tempb, res;
    for(int i=0; i<(postfix.size()); i++)
    {
        if((postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z'))
            st.push(string(1,postfix[i]));
        else
        {
            tempa = st.top(); st.pop();
            tempb = st.top(); st.pop();
            res = postfix[i] + tempb + tempa;
            st.push(res);
        }
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}
int main()
{
    string postfix = "ABC/-AK/L-*";
    prefixtoInfix(postfix);
    return 0;
}
