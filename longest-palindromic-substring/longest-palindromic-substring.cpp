class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }
        int maxLength = 0;
        int start;
        pair<int, int> l;
        for (int i = 0; i < n - 1; i++) {
            l = longestPalindrome(s, i, i);
            if (maxLength < l.second) {
                maxLength = l.second;
                start = l.first;
            }
            l = longestPalindrome(s, i, i + 1);
            if (maxLength < l.second) {
                maxLength = l.second;
                start = l.first;
            }
            
        }
        return s.substr(start, maxLength);
    }
    
private:
    pair<int, int> longestPalindrome(string s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return {i + 1, j - i - 1};
    }
};