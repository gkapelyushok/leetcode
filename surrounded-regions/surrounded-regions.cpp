class Solution {
public:
    void mark(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || 
            i >= board.size() || j >= board[0].size() ||
            board[i][j] == 'X') {
            return;
        }
        if (board[i][j] == 'O') {
            board[i][j] = 'Z';
            mark(board, i + 1, j);
            mark(board, i - 1, j);
            mark(board, i, j + 1);
            mark(board, i, j - 1);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                mark(board, 0, i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                mark(board, i, 0);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[n - 1][i] == 'O') {
                mark(board, n - 1, i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][m - 1] == 'O') {
                mark(board, i, m - 1);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'Z') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};