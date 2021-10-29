class Solution {
public:
    typedef struct point {
        int x;
        int y;
        point(int _x, int _y) : x(_x), y(_y) {}
    } point;
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<point> rotten;
        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    rotten.push(point(i, j));
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            } 
        }
        int T = -1;
        vector<point> directions = {point(0, 1),  point(1, 0),
                                    point(0, -1), point(-1, 0)};
        while (!rotten.empty()) {
            T++;
            int size = rotten.size();
            for (int i = 0; i < size; i++) {
                point p = point(rotten.front());
                rotten.pop();
                for (point d : directions) {
                    int x = d.x + p.x;
                    int y = d.y + p.y;
                    if (x >= 0 && y >= 0 &&
                        x < n  && y < m  &&
                        grid[x][y] == 1) {
                        grid[x][y] = 2;
                        rotten.push(point(x, y));
                        fresh--;
                    }
                }
            }
        }
        if (!fresh) {
            if (T == -1) {
                return 0;
            }
            return T;
        }
        return -1;
    }
};