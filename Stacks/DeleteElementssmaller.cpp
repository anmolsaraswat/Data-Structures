#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {20, 10, 25, 30, 40};
    int counter = 0;
    int n = 5, k = 2;
    std::stack<int> a;
    for(int i=0; i<n; i++)
    {
        while(!a.empty() && arr[i]>a.top() && counter != k)
        {
            a.pop();
            counter++;
        }
        a.push(arr[i]);
    }
    while(!a.empty())
    {
        cout << a.top() << endl;
        a.pop();
    }

    return 0;
}
