#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int find(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    int a = 0, b = 0;
                    if (i > 0)
                        a = dp[i - 1][j];
                    if (j > 0)
                        b = dp[i][j - 1];
                    dp[i][j] = a + b;
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return find(m, n, dp, obstacleGrid);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int numPaths = solution.uniquePathsWithObstacles(obstacleGrid);
    cout << numPaths << endl;

    return 0;
}
