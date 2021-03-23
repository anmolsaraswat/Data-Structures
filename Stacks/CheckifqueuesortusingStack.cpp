#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int s = q.size();

    std::stack<int> temp;

    int expected = 1;
    int frt;
    while (!q.empty())
    {
        frt = q.front();
        q.pop();

        if(frt == expected)
        {
            expected ++;
        }
        else
        {
            if(temp.empty())
            {
                temp.push(frt);
            }
            else if(!temp.empty() && temp.top() < frt)
            {
                cout << "This queue is not sortable using Stack.";
                return 0;
            }
            else
                temp.push(frt);
        }
    }
    while(!temp.empty() && temp.top() == expected)
    {
        temp.pop();
        expected ++;
    }
    if(expected -1 == s && temp.empty())
        cout << "This queue can be sortable";
    else
        cout << "This queue is not sortable using Stack.";
}
