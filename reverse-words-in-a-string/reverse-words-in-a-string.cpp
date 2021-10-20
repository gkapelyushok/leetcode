class Solution {
public:
    void reverseWords(string &s, int i, int j){
        while(i < j) {
          char tmp = s[i];
          s[i++] = s[j];
          s[j--] = tmp;
        } 
    }
    
    string reverseWords(string s) {        
        int i = 0, j = 0;
        bool isStart = false;
        while (true) {
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            if (i == s.length()) {
                break;
            }
            if (isStart) {
                s[j++] = ' ';
            }
            int start = j;
            while (i < s.length() && s[i] != ' ') {
                s[j++] = s[i++];
            }
            isStart = true;
            reverseWords(s, start, j - 1);
        }
        s.resize(j);
        reverseWords(s, 0, j - 1);
        return s;
    }
};