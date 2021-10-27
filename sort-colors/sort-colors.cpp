class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i0 = 0, i1 = 0, i2 = nums.size() - 1;
        while (i0 <= i2) {
            if (nums[i0] == 0) {
                swap(nums[i0], nums[i1]);
                i0++;
                i1++;
            } else if (nums[i0] == 1) {
                i0++;
            } else {
                swap(nums[i0], nums[i2]);
                i2--;
            }
        }
    }
};