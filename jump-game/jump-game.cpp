class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_i = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_i) {
                return false;
            }
            if (i + nums[i] > max_i) {
                max_i = i + nums[i];
            }
        }
        return true;
    }
};