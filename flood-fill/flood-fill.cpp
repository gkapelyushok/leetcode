class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int color = -1) {
        if (color == -1) {
            if (image[sr][sc] == newColor) {
                return image;
            }
            color = image[sr][sc];
        }
        if (sr < 0 || sc < 0 ||
            sr >= image.size() || sc >= image[0].size() ||
            image[sr][sc] != color) {
            return {{}};
        }
        image[sr][sc] = newColor;
        floodFill(image, sr + 1, sc, newColor, color);
        floodFill(image, sr, sc + 1, newColor, color);
        floodFill(image, sr - 1, sc, newColor, color);
        floodFill(image, sr, sc - 1, newColor, color);
        return image;
    }
};

//000
//011 color = 1