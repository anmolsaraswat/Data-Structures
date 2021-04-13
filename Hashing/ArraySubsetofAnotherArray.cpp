#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };

    int l1 = sizeof(arr1)/sizeof(arr1[0]);
    int l2 = sizeof(arr2)/sizeof(arr2[0]);

    set<int> s;
    for(int i=0; i<l1; i++)
        s.insert(arr1[i]);
    for(int i=0; i<l2 ;i++)
    {
        if(s.find(arr2[i]) == s.end())
        {
            cout << "The array is not a subset of given array.";
            return 0;
        }
    }
    cout << "The array is a subset of given array.";

    return 0;
}
