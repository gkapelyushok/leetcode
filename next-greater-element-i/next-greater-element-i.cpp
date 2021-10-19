class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for (auto i : nums2) {
            while (!s.empty() && i > s.top()) {
                m[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for (auto &i : nums1) {
            if (m.count(i)) {
                i = m[i];
            } else {
                i = -1;
            }
        }
        return nums1;
    }
};