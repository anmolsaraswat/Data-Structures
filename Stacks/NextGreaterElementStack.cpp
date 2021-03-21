#include<bits/stdc++.h>
using namespace std;

int main()
{
    std::stack<int> s;
    int arr[] = {11, 13, 21, 3, 11};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<arrLen; i++)
    {
        if(s.empty())
        {
            s.push(arr[i]);
        }
        else if(s.top() > arr[i])
            s.push(arr[i]);
        else
        {
            while((arr[i] > s.top()) && !s.empty())
            {
                cout << "Next Greatest of " << s.top() << " is " << arr[i] << endl;
                s.pop();
            }
            s.push(arr[i]);
        }
    }
}
