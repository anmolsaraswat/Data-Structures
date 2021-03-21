#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {11, 13, 21, 3};
    int arrlen = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<arrlen; i++)
    {
        for(int j=i+1; j<arrlen; j++)
        {
            if(arr[j] > arr[i])
            {
                cout << "Next Greater of " << arr[i] << " is " << arr[j] << endl;
                break;
            }
        }
        cout << "Next Greater of " << arr[i] << " is  " << arr[i] << endl;
    }
}
