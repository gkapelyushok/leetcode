class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<int> dp(m + 1, INT_MAX);
        dp[m] = 1;
        for (int i = n - 1; i >=0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[j] = max(min(dp[j], dp[j+1]) - dungeon[i][j], 1);
                if (i == n - 1 && j == m - 1) {
                    dp[m] = INT_MAX;
                }
            }
        }
        return dp[0];
    }
};