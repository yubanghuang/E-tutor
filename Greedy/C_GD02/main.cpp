#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        int nums[n],sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> nums[i];
            sum += nums[i];
        }
        bool dp[sum] = {0};
        dp[0] = true;
        for( int num : nums)
            for(int i=sum/2;i-num>=0;i--)
                dp[i] |= dp[i-num];     // dp[k] -> true 表示 k 能在給定陣列中湊出
        cout << ( (dp[sum/2] && !(sum&1))? "YES" : "NO") << endl;
    }
}