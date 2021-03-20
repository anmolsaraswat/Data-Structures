#include<bits/stdc++.h>
using namespace std;

prefixtoInfix(string prefix)
{
    std::stack<string> st;
    string tempa, tempb, res;
    for(int i=(prefix.size()-1); i>=0; i--)
    {
        if((prefix[i]>='a' && prefix[i]<='z') || (prefix[i]>='A' && prefix[i]<='Z'))
            st.push(string(1,prefix[i]));
        else
        {
            tempa = st.top(); st.pop();
            tempb = st.top(); st.pop();
            res = tempa +tempb + prefix[i] ;
            st.push(res);
        }
    }
    cout << st.top();
}
int main()
{
    string prefix = "*-A/BC-/AKL";
    prefixtoInfix(prefix);
    return 0;
}
