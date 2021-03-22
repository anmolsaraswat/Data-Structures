#include<bits/stdc++.h>
using namespace std;

std::stack<char> st;



void deletemid(int len, int curr)
{
    if(st.empty() || curr == len-1)
        return;
    char temp = st.top();
    st.pop();
    deletemid(len, curr+1);
    if(curr != len/2)
        st.push(temp);
}
int main()
{
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    st.push('5');
    st.push('6');
    st.push('7');

    deletemid(st.size(), 0);

    while(!st.empty())
    {
        cout<< st.top() << endl;
        st.pop();
    }
}
