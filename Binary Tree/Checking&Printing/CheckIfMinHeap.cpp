#include<bits/stdc++.h>
using namespace std;


bool isMinHeap(int level[], int n)
{
    for(int i=(n/2-1); i>=0; i--)
    {
        if(level[i] > level[2*i+1])
            return false;

        if(2*i+2 < n)
        {
            if(level[i] > level[2*i+2])
                return false;
        }
    }
}

int main()
{
    int level[] = {10, 15, 14, 25, 30};
    int n = sizeof(level)/sizeof(level[0]);
    if(isMinHeap(level, n))
        cout << "True";
    else
        cout << "False";

    return 0;
}
