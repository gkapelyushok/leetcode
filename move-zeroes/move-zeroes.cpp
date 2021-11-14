class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int i : nums) {
            if (i != 0) {
                nums[pos++] = i;
            }   
        } 
        while (pos < nums.size()) {
            nums[pos++] = 0;
        }
    }
};