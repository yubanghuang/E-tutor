#include <bits/stdc++.h>

using namespace std;

int N;
bool findexit=false;
void backtracking(vector<string>&maze,int row ,int col)
{

    if(row == N-2 && col == N-2)
    {
        maze[row][col] = '#';
        findexit = true ;
    }
    else
    {
        maze[row][col] = '#';
        if(maze[row][col+1] == '0' && !findexit)
            backtracking(maze,row,col+1);
        if(maze[row+1][col] == '0' && !findexit)
            backtracking(maze,row+1,col);
        if(maze[row][col-1] == '0' && !findexit)
            backtracking(maze,row-1,col);
        if(maze[row-1][col] == '0' && !findexit)
            backtracking(maze,row,col-1);
        if(!findexit) maze[row][col] = '0';
    }
}
int main()
{
    vector<string>maze;
    string str;
    N=0;
    while(getline(cin,str,'\n'))
    {
        if(str.empty()) break;
        string filtered_str="";
        for( char c : str )
            if(c != ' ')
                filtered_str+=c;
        maze.push_back(filtered_str);
        N++;
    }
    backtracking(maze,1,1);
    for(string str : maze)
    {
        for(int i=0;i<str.length();i++)
            if(i==0)
                cout << str[i];
            else
                cout  << ' ' << str[i];
        cout << '\n';
    }
    cout << '\n';
}