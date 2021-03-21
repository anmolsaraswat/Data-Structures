#include<bits/stdc++.h>
using namespace std;

int main()
{
    std::stack<int> s;
    int arr[] = {11, 13, 21, 3, 11};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    s.push(arr[0]);
    for(int i=1; i<arrLen; i++)
    {
        if(s.empty())
        {
            s.push(arr[i]);
        }
        while(!s.empty() && (arr[i] > s.top()))
        {
            cout << "Next Greatest of " << s.top() << " is " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while(!s.empty())
    {
        cout << s.top() << endl; s.pop();
    }
}
