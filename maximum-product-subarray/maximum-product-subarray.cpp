class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minn, maxx, result;
        minn = maxx = result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(minn, maxx);
            }
            minn = min(nums[i], minn * nums[i]);
            maxx = max(nums[i], maxx * nums[i]);
            
            result = max(result, maxx);
        }
        return result;
    }
};