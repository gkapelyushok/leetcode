class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dp(n, INT_MAX);
        dp[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            for (vector<int> t : times) {
                int u = t[0] - 1, v = t[1] - 1, w = t[2];
                if (dp[u] != INT_MAX ) {
                    dp[v] = min(dp[v], dp[u] + w);
                }
            }
        }
        int max_t = 0;
        for (int i : dp) {
            max_t = max(max_t, i);
        }
        return max_t == INT_MAX ? -1 : max_t;
    }
};