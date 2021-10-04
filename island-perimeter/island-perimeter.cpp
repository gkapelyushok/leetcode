class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0, rep = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    cnt++;
                    if (i > 0) rep += grid[i-1][j];
                    if (j > 0) rep += grid[i][j-1];
                }
            }
        }
        return cnt * 4 - rep * 2;
    }
};