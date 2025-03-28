#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return -1;
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        int totfre = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    totfre++;
                }
                else if(grid[i][j]==2) {
                    q.push({{i,j},0});
                }
            }
        }
        int ans = 0, temp = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            ans = max(ans, t);
            for (int i = 0; i < 4; i++) {
                int dr = r + dx[i];
                int dc = c + dy[i];
                if (dr >= 0 && dr < m && dc >= 0 && dc < n && vis[dr][dc]==0 && grid[dr][dc] == 1) {
                    q.push({{dr,dc},t+1});
                    vis[dr][dc] = 2;
                    temp++;
                }
            }
        }
        if (temp != totfre) return -1;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    int minutes = sol.orangesRotting(grid);
    cout << "Minutes to rot all oranges: " << minutes << endl;
    return 0;
}