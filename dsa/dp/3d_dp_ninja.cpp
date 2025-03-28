#include <bits/stdc++.h>
using namespace std;

int maxChocoUtil(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
        return -1e9;

    if (i == m - 1) {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;

    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            int ans;

            if (j1 == j2)
                ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, m, n, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, m, n, grid, dp);

            maxi = max(maxi, ans);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int m, int n, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    return maxChocoUtil(0, 0, n - 1, m, n, grid, dp);
}

int main() {
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int m = matrix.size();
    int n = matrix[0].size();

    cout << maximumChocolates(m, n, matrix) << endl;

    return 0;
}
