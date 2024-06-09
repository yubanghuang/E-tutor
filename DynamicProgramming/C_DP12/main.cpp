#include <iostream>
using namespace std;

int64_t gcd(int64_t a , int64_t b)
{
    if(b > a)   b^=a^=b^=a;
    int64_t tmp;
    while(b>0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main()
{
    int64_t n,x;
    int64_t dp[21][130]={0};
    dp[0][0] = 1;
    for(int i=1;i<=20;i++)
        for(int j=i; j<=6*i;j++)
            for(int k=1;k<=6;k++) 
                if(j-k >= (i-1)) dp[i][j] += dp[i-1][j-k];
    while(cin >> n >> x)
    {
        int64_t prob=0,total_prob=0,g;
        for(int i=n;i<=6*n;i++)
        {
            if( i >= x) prob += dp[n][i];
            total_prob += dp[n][i];
        }
        g = gcd(total_prob,prob);
        if(prob != 0)
            cout << prob/g << " / " << total_prob/g << endl;
        else
            cout << 0 << endl;
    }
}
