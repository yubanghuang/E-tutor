#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tcase;cin >> tcase;
    while(tcase--)
    {
        int a,b;
        cin >> a >> b;
        int arr1[a]={0};
        int arr2[b]={0};
        int total=0;
        
        for(int i=0;i<a;i++) 
            cin >> arr1[i],total+=arr1[i];

        for(int i=0;i<b;i++) 
            cin >> arr2[i];

        bool dp[200001] = {false};
        dp[0] = true;
        for(int i : arr1) 
            for(int j=total;j>=i;j--)
                dp[j] = dp[j-i] || dp[j];
        int correct_items = 0;
        for(int i : arr2)
            if(dp[i]) 
                correct_items++;
        cout << correct_items << endl;
    }
}
