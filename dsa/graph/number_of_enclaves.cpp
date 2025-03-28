//number of cells which are not reachable from edge land points anyway
//visit all cells from land at edges and count total cells which are not reachable

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if (grid[i][n - 1] == 1) {
                q.push({i, n - 1});
                vis[i][n - 1] = 1;
            }
        }
        for (int i = 1; i < n - 1; i++) {
            if (grid[0][i] == 1) {
                q.push({0, i});
                vis[0][i] = 1;
            }
            if (grid[m - 1][i] == 1) {
                q.push({m - 1, i});
                vis[m - 1][i] = 1;
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    cout << "Number of enclaved land cells: " << solution.numEnclaves(grid) << endl;

    return 0;
}
