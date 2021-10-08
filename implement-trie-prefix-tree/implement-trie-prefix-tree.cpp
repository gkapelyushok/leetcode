class Trie {
public:
    Trie() {
        node = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = node;
        for (int i = 0; i < word.size(); i++) {
            if (cur->children[word[i] - 'a'] == NULL) {
                cur->children[word[i] - 'a'] = new TrieNode();
            } 
            cur = cur->children[word[i] - 'a'];
        }
        cur->isLast = true;
    }
    
    bool search(string word) {
        TrieNode *cur = node;
        for (int i = 0; i < word.size(); i++) {
            if (cur->children[word[i] - 'a'] == NULL) {
                return false;
            } 
            cur = cur->children[word[i] - 'a'];
        }
        return cur->isLast;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = node;
        for (int i = 0; i < prefix.size(); i++) {
            if (cur->children[prefix[i] - 'a'] == NULL) {
                return false;
            } 
            cur = cur->children[prefix[i] - 'a'];
        }
        return true;
    }
    
private:
    typedef struct TrieNode {
        TrieNode *children[26];
        bool isLast;
    }TrieNode;
    
    TrieNode *node;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */