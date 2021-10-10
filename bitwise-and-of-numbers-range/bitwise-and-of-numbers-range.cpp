class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (!left || !right) {
            return 0;
        }
        int i = 0;
        while (left != right) {
            left  /= 2;
            right /= 2;
            i++;
        }
        return left << i;
    }
};