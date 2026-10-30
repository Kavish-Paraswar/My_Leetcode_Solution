class Solution {
public:
    int m, n, word_size;
    bool flag = false;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(string& word, vector<vector<char>>& board, int row, int col,
             int idx) {

        if (idx == word_size) {
            // vis.assign(m, vector<bool>(n, false));
            flag = true;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_row = row + dir[i][0], next_col = col + dir[i][1];

            if (next_row >= 0 && next_row < m && next_col >= 0 &&
                next_col < n && board[next_row][next_col] != '0' &&
                board[next_row][next_col] == word[idx]) {
                char temp = board[next_row][next_col];
                board[next_row][next_col] = '0';
                // vis[next_row][next_col] = true;
                dfs(word, board, next_row, next_col, idx + 1);

                board[next_row][next_col] = temp;
                // vis[next_row][next_col] = false;

                if (flag)
                    return;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size(), n = board[0].size(), word_size = word.size();

        if (word_size > m * n)
            return false;
        // vector<vector<bool>> vis(m, vector<bool>(n, false));

        // if(word_size == 1)
        //     return wordd[0] == board[0][0]

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (flag)
                    return true;

                if (word[0] == board[i][j]) {
                    // vis[i][j] = true;
                    char temp = board[i][j];
                    board[i][j] = '0';
                    dfs(word, board, i, j, 1);
                    board[i][j] = temp;
                    // vis[i][j] = false;
                }
            }
        }

        return flag;
    }
};