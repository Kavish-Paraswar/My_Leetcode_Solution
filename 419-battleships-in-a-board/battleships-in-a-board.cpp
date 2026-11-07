class Solution {
public:
    int m, n;

    // void dfs(vector<vector<char>>& board, int row, int col) {

    //     stack<pair<int, int>> s;
    //     s.push({row, col});

    //     while (!s.empty()) {
    //         auto [cur_row, cur_col] = s.top();
    //         s.pop();

    //         while () {
    //         }

    //         while () {
    //         }
    //     }
    // }
    int countBattleships(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    bool flag = true;
                    int above = i - 1, lefty = j - 1;

                    if (above >= 0 && above < m && board[above][j] == 'X') {
                        flag = false;
                    }
                    if (lefty >= 0 && lefty < n && board[i][lefty] == 'X') {
                        flag = false;
                    }

                    if (flag)
                        count++;
                    // dfs(board, i, j);
                }
            }
        }

        return count;
    }
};