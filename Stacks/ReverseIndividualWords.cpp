#include<bits/stdc++.h>
using namespace std;


rev(string s)
{
    std::stack<char> c;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ' || i == s.size()-1)
        {
            while(!c.empty())
            {
                cout<<c.top(); c.pop();
            }
        }
        else
            c.push(s[i]);
    }
}



int main()
{
    string s = "Geeks for Geeks";
    rev(s);
}
