#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        int arr[n];
        bool haszero=false;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            if(arr[i]==0)
                haszero = true;
        }
        sort(arr,arr+n,[](int a, int b){
            return a < b;
        });
        for(int i=0;i<n;i++)
            if(arr[i] != 0 && haszero)
            {
                arr[i] ^= arr[0] ^= arr[i] ^= arr[0];    
                arr[i+1] ^= arr[1] ^= arr[i+1] ^= arr[1];    
                break;
            }
        uint64_t a=0,b=0;
        for(uint64_t i=0,pow=1; i < n; i++,pow*=10)
        {
            a = a*10 + arr[i];
            if(i+1 < n)
                b = b*10 + arr[i+1],i++;
        }
        cout << a + b << endl;
    }
}