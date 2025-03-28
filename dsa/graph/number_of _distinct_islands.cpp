#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int baseR, int baseC, vector<pair<int, int>>& shape) {
        int m = grid.size();
        int n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return;
        }
        grid[r][c] = 0;
        shape.push_back({r - baseR, c - baseC});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + dr[i], c + dc[i], baseR, baseC, shape);
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int, int>>> uniqueShapes;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(grid, i, j, i, j, shape);
                    uniqueShapes.insert(shape);
                }
            }
        }
        
        return uniqueShapes.size();
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1}
    };

    cout << "Number of distinct islands: " << solution.numDistinctIslands(grid) << endl;

    return 0;
}
