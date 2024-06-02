#include <bits/stdc++.h>
using namespace std;

int N,M,H,K,ans;
int movingdirection[8][2]= {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

void backtracking(vector<vector<bool>> &map,int x, int y,int prev_direction)
{
    if( x == H && y == K && map[x][y])
        ans++;
    else
    {
        for(int i=0;i<8;i++)
        {
            int next_x = x + movingdirection[i][0];
            int next_y = y + movingdirection[i][1];
            if( (0 <= next_x && next_x <= N) && (0 <= next_y && next_y <= M) && !map[next_x][next_y])
            {
                map[next_x][next_y] = true;     // 往下個移動點
                backtracking(map,next_x,next_y,i);
                map[next_x][next_y] = false;    // 往回上個移動點
            }
        }
    }

}
int main()
{
    while(cin >> N >> M >> H >> K)
    {
        ans = 0;
        vector<vector<bool>> map(M+1,vector<bool>(N+1,false));
        backtracking(map,H,K,-1);
        cout << ans << endl;
    }
}