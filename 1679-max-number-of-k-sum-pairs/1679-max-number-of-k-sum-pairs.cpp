class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> map;
        for (int i : nums) {
            int res = k - i;
            if (map.count(res)) {
                if (map[res] == 1) {
                    map.erase(res);
                } else {
                    map[res]--;
                }
                count++;
            } else {
                map[i]++;
            }
        }
        return count;
    }
};