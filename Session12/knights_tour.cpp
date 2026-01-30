//time complexity = 8 ^ (n*m)
// this is not the exact time complexity practically, fue to pruning 

#include <bits/stdc++.h>
using namespace std;

vector<int> x = {2, 2, -1, -2, -2, -1, 1, 1};
vector<int> y = {1, -1, 2, 1, -1, -2, -2, 2};
vector<vector<int>> board;
int n, m;

bool isValid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m && board[x][y] == -1);
}

bool solve(int r, int c, int move)
{
    if(move == n * m) return true;

    for(int i = 0; i < 8; i++)
    {    
        int nx = r + x[i];
        int ny = c + y[i];

        if(isValid(nx, ny))
        {
            board[nx][ny] = move;
            if(solve(nx, ny, move + 1)) return true;
            board[nx][ny] = -1;
        }

    }
    return false;
}

int main()
{
    cin>>n>>m;
    board.assign(n, vector<int>(m, -1)); 
    board[0][0] = 0;

    if(solve(0, 0, 1))
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }


    return 0;
}

