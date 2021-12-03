class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums[0];
        }        
        int a = nums[0];
        int b = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int tmp = b;
            b = max(b, a + nums[i]);
            a = tmp; 
        }
        return b;
        
    }
};

 