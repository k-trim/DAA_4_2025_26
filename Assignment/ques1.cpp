// Time Complexity: O(N!), where N is the size of the chessboard
// Space Complexity: O(N^2) + O(N)

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> result;
vector<string> board;
int n;

vector<int> col, diag1, diag2;

void solve(int row)
{
    if(row == n) 
    {
        result.push_back(board);
        return;
    }

    for(int c = 0; c < n; c++)
    {
        if(col[c] == 0 && diag1[row + c] == 0 && diag2[row - c + n - 1] == 0)
        {
            board[row][c] = 'Q';
            col[c] = 1;
            diag1[row + c] = 1;
            diag2[row - c + n - 1] = 1;
            solve(row + 1);

            board[row][c] = '.';
            col[c] = 0;
            diag1[row + c] = 0;
            diag2[row - c + n - 1] = 0;
        }

    }
}

int main()
{
    cin>>n;
    board = vector<string>(n, string(n, '.'));
    col = vector<int>(n, 0);
    diag1 = vector<int>(2*n - 1, 0);
    diag2 = vector<int>(2*n - 1, 0);

    solve(0);

    for(auto &b : result)
    {
        for(auto &row : b)
            cout << row << endl;
        cout << endl;
    }

    cout << "Total solutions: " << result.size() << endl;
    return 0;
}