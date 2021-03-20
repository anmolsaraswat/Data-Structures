#include<bits/stdc++.h>
using namespace std;

evaluatePostfix(string postfix)
{
    std::stack<int> st;
    int tempa, tempb;
    for(int i=0; i<postfix.size(); i++)
    {
        if(postfix[i]>='0' && postfix[i]<='9')
        {
            st.push(postfix[i]-'0');
        }
        else
        {
            tempa = st.top();
            st.pop();
            tempb = st.top();
            st.pop();
            if(postfix[i] == '+')
                st.push(tempb+tempa);
            else if(postfix[i] == '-')
                st.push(tempb-tempa);
            else if(postfix[i] == '*')
                st.push(tempb*tempa);
            else if(postfix[i] == '/')
                st.push(tempb/tempa);
            else if(postfix[i] == '^')
                st.push(tempb^tempa);
        }
    }
    cout << st.top();
}


int main()
{
    string postfix = "53+62/*35*+";
    evaluatePostfix(postfix);
    return 0;
}
