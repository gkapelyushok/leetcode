class Solution {
public:
    void dfs (int x, int y, int steps, int empty, vector<vector<int>> &grid, int &result ) {
        if (x < 0 || x >= grid.size()    ||
            y < 0 || y >= grid[0].size() ||
            grid[x][y] == -1) {
            return;
        }
        if (grid[x][y] == 2) {
            if (steps == empty) {
                result++;
            }
            return;
        }
        grid[x][y] = -1;
        dfs(x + 1, y, steps + 1, empty, grid, result);
        dfs(x - 1, y, steps + 1, empty, grid, result);
        dfs(x, y + 1, steps + 1, empty, grid, result);
        dfs(x, y - 1, steps + 1, empty, grid, result);
        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int empty = 1;
        int x, y;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    empty++;
                }
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        int result = 0;
        dfs(x, y, 0, empty, grid, result);
        return result;
    }
};