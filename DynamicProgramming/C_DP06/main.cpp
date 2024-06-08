#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    int dp[1000][2]={0};
    dp[0][1] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    while(cin >> N)
    {
        for(int i=2;i<=N;i++)
        {
            // k     k-1
            // 公 = 母 + 公 
            // 母 = 公 + 不死母
            dp[i][0] = dp[i-1][1] + dp[0][1];
            dp[i][1] = dp[i-1][0] + dp[i-1][1];
        }
        cout << dp[N][1] << " " << dp[N][0] << endl;
    }
}