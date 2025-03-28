#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int temp) {
        int rows = image.size();
        int colns = image[0].size();
        if (sr < 0 || sc < 0 || sr >= rows || sc >= colns || image[sr][sc] != temp || image[sr][sc] == color)
            return;
        image[sr][sc] = color;
        dfs(image, sr + 1, sc, color, temp);
        dfs(image, sr - 1, sc, color, temp);
        dfs(image, sr, sc + 1, color, temp);
        dfs(image, sr, sc - 1, color, temp);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int temp = image[sr][sc];
        dfs(image, sr, sc, color, temp);
        return image;
    }
};

void printImage(const vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;

    cout << "Original image:" << endl;
    printImage(image);

    vector<vector<int>> result = solution.floodFill(image, sr, sc, color);

    cout << "Image after flood fill:" << endl;
    printImage(result);

    return 0;
}
