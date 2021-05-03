#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    int len = sizeof(arr)/sizeof(arr[0]);
    int maxDis = INT_MIN;
    unordered_map<int, int> ind;
    for(int i=0; i<len; i++)
    {
        if(!ind[arr[i]])
            ind[arr[i]] = i;
        else
        {
            if(maxDis < (i - ind[arr[i]]))
                maxDis = i-ind[arr[i]];
        }
    }

    cout << maxDis;
    return 0;
}
