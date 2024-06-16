#include <bits/stdc++.h>
using namespace std;


int n;
bool findexit;
char maze[21][21];
void backtracking(int row,int col)
{
    if(row == n-2 && col == n-2)
    {
        maze[row][col] = '#';
        findexit = true;
    }
    else
    {
        maze[row][col] = '#';
        if(maze[row+1][col] == '0' && !findexit)    // 下
            backtracking(row+1,col);
        if(maze[row-1][col] == '0' && !findexit)    // 上
            backtracking(row-1,col);
        if(maze[row][col-1] == '0' && !findexit)    // 左
            backtracking(row,col-1);
        if(maze[row][col+1] == '0' && !findexit)    // 右
            backtracking(row,col+1);   
        if(!findexit) maze[row][col] = '*';
    }
}
int main()
{
    while(cin >> n)
    {
        findexit = false;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> maze[i][j];
        backtracking(1,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(j==0)
                    cout << maze[i][j];
                else
                    cout << " " << maze[i][j];
            cout << endl;
        }
    }
}