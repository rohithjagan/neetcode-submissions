class Solution {
public:
    bool done(int i, int j, string& word, vector<vector<char>>& board, int count, vector<vector<int>>& check) {
        if (count == word.size()) {
            return true;
        }
        if (i - 1 >= 0 && board[i - 1][j] == word[count] && check[i - 1][j] == 0) {
            check[i - 1][j] = 1;
            if (done(i - 1, j, word, board, count + 1, check))
                return true;
            check[i - 1][j] = 0;
        }
        if (i + 1 < board.size() && board[i + 1][j] == word[count] && check[i + 1][j] == 0) {
            check[i + 1][j] = 1;
            if (done(i + 1, j, word, board, count + 1, check))
                return true;
            check[i + 1][j] = 0;
        }
        if (j - 1 >= 0 &&
            board[i][j - 1] == word[count] && check[i][j - 1] == 0) {
            check[i][j - 1] = 1;
            if (done(i, j - 1, word, board, count + 1, check))
                return true;
            check[i][j - 1] = 0;
        }
        if (j + 1 < board[0].size() &&
            board[i][j + 1] == word[count] && check[i][j + 1] == 0) {
            check[i][j + 1] = 1;
            if (done(i, j + 1, word, board, count + 1, check))
                return true;
            check[i][j + 1] = 0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> check(
                        board.size(),
                        vector<int>(board[0].size(), 0)
                    );
                    check[i][j] = 1;
                    if (done(i, j, word, board, 1, check))
                        return true;
                }
            }
        }
        return false;
    }
};