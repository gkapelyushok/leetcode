class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (auto c : s) {
            freq[c]++;
        }
        map<int, vector<char>> freq2;
        for (auto v : freq) {
            freq2[-v.second].push_back(v.first);
        }
        string res;
        for (auto v : freq2) {
            for (auto u : v.second) {
                res.append(-v.first, u);
            }
        } 
        return res;
    }
};