#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    string number[11];
    int start_time[11]={0},end_time[11]={0},score[11]={0};
    int dp[25]={0};
    string prev[25];
    for(int i = 1;i<=n;i++)
    {
        cin >> number[i] >> start_time[i] >> end_time[i] >> score[i];
        start_time[i] /= 100;
        end_time[i] /= 100;
        dp[end_time[i]] = score[i];
        prev[end_time[i]] = number[i] + " ";
    }
    int max_score = 0;
    int index = 0;
    for(int time=0;time<=24;time++)
    {
        for(int i=1;i<=n;i++)
        {
            if(time <= start_time[i])
                if(dp[end_time[i]] < dp[time] + score[i])
                {
                    dp[end_time[i]] = dp[time] + score[i];
                    prev[end_time[i]] = prev[time] + number[i] + " ";
                }
            if(max_score < dp[time])
                max_score = dp[time],index = time;
        }
    }
    cout << prev[index] << dp[index] << endl;
}