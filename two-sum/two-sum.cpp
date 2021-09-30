class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> snums = nums;
        sort(snums.begin(), snums.end());
        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
             if (snums[i] + snums[j] > target) {
                 j--;
             } else if (snums[i] + snums[j] < target) {
                 i++;
             } else {     
                break;
            }
        }
        vector<int> solution;
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] == snums[i]) {
                solution.push_back(k);
                break;
            } 
        }
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] == snums[j] && k != solution[0]) {
                solution.push_back(k);
                break;
            } 
        }
        return solution;
    }
};