class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0 || target < nums[0]) {
            return 0;
        }
        if (target > nums[nums.size() - 1]) {
            return nums.size();
        }
        int l = 0;
        int r = nums.size() - 1;        
        while (l < r) {
            int m = l + (r - l) / 2;
            if (target < nums[m]) {
                r = m;
            } else if (target > nums[m]) {
                l = m + 1;
            } else {
                return m;
            }
        }
        return r;
    }
};