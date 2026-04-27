class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    vector<int> col, diag1, diag2;
    void solve(int row, int n)
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
                solve(row + 1, n);
                board[row][c] = '.';
                col[c] = 0;
                diag1[row + c] = 0;
                diag2[row - c + n - 1] = 0;
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        col = vector<int>(n, 0);
        diag1 = vector<int>(2*n - 1, 0);
        diag2 = vector<int> (2*n - 1, 0);
        solve(0, n);
        
        return result;

    }
};
