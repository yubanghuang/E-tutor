#include <bits/stdc++.h>
using namespace std;
int n;
char maze[52][52];
int direction[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
int Devil_x;
int Devil_y;
bool findpos=false;
void dfs(int hero_y,int hero_x)
{
    for(int i=3;i>=0&&!findpos;i--)
    {
        int next_y = hero_y + direction[i][0];
        int next_x = hero_x + direction[i][1];
        maze[hero_y][hero_x] = '0';
        if( 0 <= next_y && next_y <= n && 0 <= next_x && next_x <= n && maze[next_y][next_x] == '1')
            dfs(next_y,next_x);
        maze[hero_y][hero_x] = '1';
    }
    if(!findpos)
    {
        findpos = true;
        Devil_y = hero_y;
        Devil_x = hero_x;
    }
    return;
}
int main()
{
    while(cin >> n)
    {
        findpos = false;
        int hero_x,hero_y;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cin >> maze[i][j];
                if(maze[i][j] == 'S')
                {
                    hero_y = i;
                    hero_x = j;
                }
            }
        dfs(hero_y,hero_x);
        maze[hero_y][hero_x] = 'S';
        maze[Devil_y][Devil_x] = '#';
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout << maze[i][j];
            cout << "\n";
        }
            
    }
}
