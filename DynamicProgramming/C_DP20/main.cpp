#include <iostream>
#include <algorithm>
#include <cstring>
int dp[300][300];
int func(int m, int n)
{
    if (m == 0 || n == 0) return m + n;
    if (dp[m][n] != -1) return dp[m][n];
    int tmp = 0;
    tmp = func(m - 1, std::min(func(m / 2, n / 2),n-1)) + func(std::min(m - 1, func(m / 4, n / 2)), n / 2);
    return dp[m][n] = tmp;
}

int main()
{
    std::fill(dp[0],dp[0]+300*300,-1); 
    int m, n;
    while (std::cin >> m >> n)
        std::cout << func(m, n) << std::endl;
}