class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        if (t.size() == 0) {
            return {};
        }
        stack<pair<int, int>> stack;
        stack.push({t[t.size() - 1], 0});
        vector<int> result(t.size());
        for (int i = t.size() - 2; i >= 0; i--) {
            int cnt = 1;
            while (!stack.empty() && t[i] >= stack.top().first) {
                cnt += stack.top().second;
                stack.pop();
            }
            if (stack.empty()) {
                cnt = 0;
            }
            stack.push({t[i], cnt});
            result[i] = cnt;
        }
        return result;
    }
};