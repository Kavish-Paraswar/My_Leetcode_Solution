class Solution {
public:
    // int m;
    bool check(vector<vector<char>>& board, int row, int col, char k) {

        for (int i = 0; i < 9; i++) {
            if (i != row && board[i][col] == k) {
                return false;
            }

            if (i != col && board[row][i] == k) {
                return false;
            }

            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;

            if ((r != row || c != col) && board[r][c] == k) {
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

                        board[i][j] = k;
                        if (check(board, i, j, k)) {

                            if (dfs(board))
                                return true;
                        }
                        board[i][j] = '.';
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