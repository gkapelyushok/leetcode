class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long aXORb = 0;
        for (int i : nums) {
            aXORb ^= i;
        }
        int mask = aXORb & -aXORb;
        int a = 0;
        for (int i : nums) {
            if (i & mask) {
               a ^= i; 
            }
        }
        return {a, (int)aXORb ^ a};
    }
};