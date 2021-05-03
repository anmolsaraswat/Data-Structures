#include<bits/stdc++.h>

using namespace std;

int main()
{
    int A[] = {1, 2, 2, 2, 1};
    int len = sizeof(A)/sizeof(A[0]);

    unordered_map<int, int> left;
    unordered_map<int, int> count;

    int mx = 0;

    int mn, strindex;

    for(int i=0; i<len; i++)
    {
        int x = A[i];

        if(count[x] == 0)
        {
            left[x] = i;
            count[x] = 1;
        }
        else
            count[x]++;

        if(count[x] > mx)
        {
            mx = count[x];
            mn = i- left[x] +1;
            strindex = left[x];
        }

        else if(count[x] == mx && i - left[x] + 1 < mn)
        {
            mn = i - left[x] + 1;
            strindex = left[x];
        }
    }
    for(int i = strindex; i< strindex + mn; i++)
        cout << A[i] << " ";
}
