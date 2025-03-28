#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int bottomUp(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize the bottom row of dp with the values from the triangle
    for (int i = 0; i < n; i++) {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    // Build the dp table from bottom to top
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    return dp[0][0];
}
int find(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(m==grid.size()-1) return grid[m][n];
    if(dp[m][n]!=-1) return dp[m][n];
    int temp1=grid[m][n]+find(m+1,n,grid,dp);
    int temp2=grid[m][n]+find(m+1,n+1,grid,dp);
    return dp[m][n]=min(temp1,temp2);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // return find(0,0,triangle,dp);
        return bottomUp(triangle);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    int numPaths = solution.minimumTotal(triangle);
    cout << numPaths << endl;

    return 0;
}