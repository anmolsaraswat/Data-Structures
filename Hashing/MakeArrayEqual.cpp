#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 3, 4, 4, 2, 4};
    int len = sizeof(arr)/sizeof(arr[0]);
    unordered_map<int, int> freq;
    for(int i=0; i<len; i++)
        freq[arr[i]]++;

    int maxFre = INT_MIN;
    for(auto i = freq.begin(); i!= freq.end(); ++i)
        maxFre = max(maxFre, i->second);

    cout << maxFre;
    return 0;
}
