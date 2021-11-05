class Solution {
public:
    int arrangeCoins(int n) {
        long long D = 1 + (long long)8 * n;
        return (-1 + sqrt(D)) / 2;
    }
};