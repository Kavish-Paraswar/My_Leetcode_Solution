class Solution {
public:
    bool check(int row, int col, vector<string>& board, int n) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        int i = row - 1, j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        return true;
    }

    void helper(vector<string>& board, vector<vector<string>>& ans, int row,
                int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (check(row, col, board, n)) {

                board[row][col] = 'Q';
                helper(board, ans, row + 1, n);

                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        // vector<vector<string>> ans(n, vector<string>(n, '.'));

        // if (n == 1) {
        //     ans.push_back('Q');
        //     return ans;
        // }

        // size = n;

        helper(board, ans, 0, n);
        return ans;
    }
};