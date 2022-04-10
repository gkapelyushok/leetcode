class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i : nums) {
            map[i]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto i : map) {
            bucket[i.second].push_back(i.first);
        }
        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0 && k > 0; i--) {
            for (int j : bucket[i]) {
                result.push_back(j);
                k--;
            }
        }
        return result;
    }
};