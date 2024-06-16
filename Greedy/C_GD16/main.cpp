#include <iostream>
#include <cstring>
#define MAXLENGTH 21
using namespace std;
int dp[MAXLENGTH] = {0};
int main() 
{
    int n;
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=1;i<MAXLENGTH;i++)
        for(int j=i;j<MAXLENGTH;j++)
            dp[j] += dp[j-i];
    while(cin >> n)
        cout << dp[n] << endl;
}