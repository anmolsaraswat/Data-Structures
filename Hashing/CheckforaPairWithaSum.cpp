#include<bits/stdc++.h>
using namespace std;


int main()
{
    int A[] = { 2, 4, 9, -1, -6, 3, 5, -2};
    int sum = 7;
    int len = sizeof(A)/sizeof(A[0]);
    set<int> s;
    for(int i=0; i<len; i++)
    {
        if(s.find(sum - A[i]) != s.end())
        {
            cout << "We have a pair " << A[i] << " " << sum-A[i] << endl;
        }
        s.insert(A[i]);
    }

    return 0;
}
