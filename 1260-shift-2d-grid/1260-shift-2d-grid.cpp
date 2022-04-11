class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> result(n, vector<int>(m));
        for (int i = 0; i < n * m; i++) {
           result[(i + k) % (n * m) / m][(i + k) % (n * m) % m] = grid[i / m][i % m];
        }
        return result;
    }
};