#include <bits/stdc++.h>
using namespace std;

int n,total,square_len;
bool findsquare = false;
bool visited[20];
int sticks[20];

void backtracking(int count_squre_side,int cur_side_len)
{
    if(count_squre_side == 4)
    {
        findsquare = true;
    }
    else
    {
        if(cur_side_len == square_len)
            backtracking(count_squre_side+1,0);
        else
        {
            for(int i = 0 ;i<n;i++)
            {
                if(!visited[i] && cur_side_len+sticks[i] <= square_len && !findsquare)
                {
                    visited[i] = true;
                    backtracking(count_squre_side,cur_side_len+sticks[i]);
                    visited[i] = false;
                }
            }
        }
    }
}
int main()
{
    n = 0;
    while(cin >> n)
    {
        findsquare = false;
        total = 0;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++)
        {
            cin >> sticks[i];
            total += sticks[i];
        }
        square_len = total / 4 ;
        if(total % 4 == 0)
            backtracking(0,0);
        if(findsquare) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}