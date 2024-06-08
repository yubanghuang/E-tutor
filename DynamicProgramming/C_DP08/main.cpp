#include <bits/stdc++.h>
using namespace std;
int main()
{
    int coins[4] = {50,10,5,1};
    int dp[150001] ={0};
    dp[0] = 1;
    for(int coin : coins)
        for(int j = coin;j<=15000;j++)
            dp[j] = dp[j] + dp[j-coin];
    int money;
    while(cin >> money)
        cout << dp[money] << endl;
}