class Solution {
public:
    int countVowelStrings(int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        while (--n) {
            a += e + i + o + u;
            e += i + o + u;
            i += o + u;
            o += u;
        }
        return a + e + i + o + u;
    }
};