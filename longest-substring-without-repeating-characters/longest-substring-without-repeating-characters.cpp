class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            map<char, int> a;
            int cnt = 0;
            for (int j = i; j < s.size(); j++) {
                if (a[s[j]] == 0) {
                    a[s[j]]++;
                    cnt++;
                } else {
                    break;
                }
            }
            result = max(result, cnt);
        }
        return result;
    }
};