#include<bits/stdc++.h>
using namespace std;


stockspan(int price[], int size)
{

    for(int i=0; i<size; i++)
    {
        int span=0;
        for(int j=i; j>=0; j--)
        {
            if(price[j] <= price[i])
            {
                span++;
            }
            else
            {
                break;
            }
        }
        cout<< span <<endl;
    }
}
int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int size = sizeof(price)/sizeof(price[0]);
    stockspan(price, size);
}
