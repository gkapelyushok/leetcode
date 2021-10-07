class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (exist(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>> &board, string word, int i, int j, int k) {
        if (i < board.size()    &&
            j < board[0].size() &&
            i >= 0              &&
            j >= 0              &&
            board[i][j] == word[k]) {
            if (k == word.size() - 1) {
                return true;
            } else {
                char tmp = board[i][j];
                board[i][j] = '0';
                if (exist(board, word, i + 1, j, k + 1) ||
                    exist(board, word, i, j + 1, k + 1) ||
                    exist(board, word, i - 1, j, k + 1) ||
                    exist(board, word, i, j - 1, k + 1)) {
                   return true;
                }
                board[i][j] = tmp;    
            }
        } 
        return false;
    }
};