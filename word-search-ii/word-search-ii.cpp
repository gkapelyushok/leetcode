class Solution {
    public:
    typedef struct TrieNode {
        string word;
        TrieNode *nextLetters[26];
    }TrieNode;
    
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode *cur = root;
            for (int j = 0; j < words[i].size(); j++) {
                if (cur->nextLetters[words[i][j] - 'a'] == nullptr) {
                    cur->nextLetters[words[i][j] - 'a'] = new TrieNode();
                }
                cur = cur->nextLetters[words[i][j] - 'a'];
            }
            cur->word = words[i];
        }
        return root;
    }
    
    void findWords(vector<vector<char>>& board, TrieNode *cur, int i, int j, vector<string> &result) {
        if (i < board.size() &&
            j < board[0].size() &&
            i >= 0 &&
            j >= 0 &&
            board[i][j] != '0' &&
            cur->nextLetters[board[i][j] - 'a'] != NULL) {
            cur = cur->nextLetters[board[i][j] - 'a'];
            if (cur->word != "") {
                result.push_back(cur->word);
                cur->word = "";
            }
            char tmp = board[i][j];
            board[i][j] = '0';
            findWords(board, cur, i + 1, j, result);
            findWords(board, cur, i, j + 1, result);
            findWords(board, cur, i - 1, j, result);
            findWords(board, cur, i, j - 1, result);
            board[i][j] = tmp;      
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = buildTrie(words);
        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                findWords(board, root, i, j, result);
            }
        }
        return result;
    }
};