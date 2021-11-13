class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> result(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (abs(nums[l]) < abs(nums[r])) {
                result[i] = nums[r] * nums[r];
                r--;
            } else {
                result[i] = nums[l] * nums[l];
                l++;
            }
        }
        return result;
    }
};