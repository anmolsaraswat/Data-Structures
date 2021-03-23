#include<bits/stdc++.h>
using namespace std;

int main()
{
    std::stack<int> ar;
    std::stack<int> temp;

    ar.push(3);
    ar.push(55);
    ar.push(42);
    ar.push(104);
    ar.push(7);
    ar.push(15);

    while(!ar.empty())
    {
        int t = ar.top(); ar.pop();
        while(!temp.empty() && temp.top() > t)
        {
            ar.push(temp.top());
            temp.pop();
        }
        temp.push(t);
    }

    while(!temp.empty())
    {
        cout << temp.top() << endl;
        temp.pop();
    }
}
