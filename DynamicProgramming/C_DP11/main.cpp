#include <iostream>

using namespace std;
int main()
{
    int a, b;
    unsigned long long int dp[55][55] = { 0 };
    for (int i = 0; i < 55; i++)
        dp[i][0] = 1;
    for (int i = 1; i < 55; i++)
        for (int j = 1; j < 55; j++)
            if (j > i)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    while (cin >> a >> b)
    {
        cout << dp[a][b] << endl;
    }
}
