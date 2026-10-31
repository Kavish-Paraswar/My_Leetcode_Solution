class Solution {
public:
    // int m;
    bool check(vector<vector<char>>& board, int row, int col, char k) {

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == k || board[row][i] == k) {
                return false;
            }

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k) {
                return false;
            }
        }

        return true;
    }
    bool dfs(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {

                        if (check(board, i, j, k)) {
                            board[i][j] = k;

                            if (dfs(board))
                                return true;

                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int m = board.size();

        dfs(board);
    }
};