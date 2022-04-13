class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, up = 0, right = n - 1, down = n - 1, k = 0;
        vector<vector<int>> result(n, vector<int>(n));
        while (k < n * n) {
            for (int i = left; i <= right; i++) {
                result[up][i] = ++k;
            }
            up++;
            for (int i = up; i <= down; i++) {
                result[i][right] = ++k;
            }
            right--;
            for (int i = right; i >= left; i--) {
                result[down][i] = ++k;
            }
            down--;
            for (int i = down; i >= up; i--) {
                result[i][left] = ++k;
            }
            left++;
        } 
        return result;
    }
};