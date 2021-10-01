class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> a;
        int head = 0, tail = 0;
        int result = 0;
        while (tail < s.size()) {
            if (a.count(s[tail]) == 0) {
                a.insert(s[tail]);
                result = max(result, tail - head + 1);
                tail++;
            } else {
                a.erase(s[head]);
                head++;
            }
        }
        return result;
    }
};
