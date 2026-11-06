class Solution {
public:
    bool flag = false;
    int m, n, w;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int row, int col, int ind, vector<vector<char>>& board,
             string& word) {
        if (row >= m || col >= n)
            return;

        if (w == ind) {
            flag = true;
            return;
        }

        char temp = board[row][col];
        board[row][col] = '0';

        for (int i = 0; i < 4; i++) {
            int cur_row = dir[i][0] + row, cur_col = dir[i][1] + col;

            if (cur_row >= 0 && cur_row < m && cur_col < n && cur_col >= 0 &&
                board[cur_row][cur_col] != '0' &&
                board[cur_row][cur_col] == word[ind]) {

                dfs(cur_row, cur_col, ind + 1, board, word);
            }

            if (flag)
                return;
        }
        board[row][col] = temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        w = word.length();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0])
                    dfs(i, j, 1, board, word);
            }
            if (flag)
                return flag;
        }

        return flag;
    }
};