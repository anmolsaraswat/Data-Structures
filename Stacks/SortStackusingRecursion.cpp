#include<bits/stdc++.h>
using namespace std;

std::stack<int> s;


sortedInsert(int a)
{
    if(s.empty() || (a > s.top()))
        s.push(a);
    else
    {
        int temp = s.top();
        s.pop();
        sortedInsert(a);
        s.push(temp);
    }
}

sortStack()
{
    if(s.size() > 0)
    {
        int temp = s.top();
        s.pop();
        sortStack();
        sortedInsert(temp);
    }
}

int main()
{
    s.push(1);
    s.push(4);
    s.push(2);
    s.push(8);
    sortStack();

    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}
