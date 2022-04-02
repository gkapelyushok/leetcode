class Solution {
public:
    bool validPalindrome(string s) {
        int count = 0;
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            if (s[l] == s[r]) {
                count += 2;
                if (l == r) {
                    count--;
                }
            }
            l++;
            r--;
        }
        
        if (count == s.size()) {
            return true;
        }
        bool skip = false;
        int new_count = 0;
        l = 0, r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r]) {
                if (skip) {
                    break;
                } else {
                    skip = true;
                }
                l++;
            }
            if (s[l] == s[r]) {
                new_count += 2;
                if (l == r) {
                    new_count--;
                }
            }
            l++;
            r--;
        }
        if (new_count == s.size() - 1) {
            return true;
        }
        skip = false;
        new_count = 0;
        l = 0, r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r]) {
                if (skip) {
                    return false;
                } else {
                    skip = true;
                }
                r--;
            }
            if (s[l] == s[r]) {
                new_count += 2;
                if (l == r) {
                    new_count--;
                }
            }
            l++;
            r--;
        }
        if (new_count == s.size() - 1) {
            return true;
        }
        return false;
    }
};