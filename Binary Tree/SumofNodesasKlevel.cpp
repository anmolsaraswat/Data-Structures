#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "(0(5(6()())(4()(9()())))(7(1()())(3()())))";
    int k = 2;
    int level =-1;
    int sum = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(')
            level++;
        else if(s[i] == ')')
            level --;
        else
        {
            if(level == k)
                sum += (s[i] - '0');
        }

    }
    cout << "Sum : " << sum;

}
