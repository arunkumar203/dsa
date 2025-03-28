#include<bits/stdc++.h>
using namespace std;
//stat from any point in the first row and find the minimum path sum to reach the last row
class Solution {
public:
int find(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(n<0||n>=grid[0].size()) return 1e9;
    if(m==grid.size()-1) return grid[m][n];
    if(dp[m][n]!=-1) return dp[m][n];
    int temp1=grid[m][n]+find(m+1,n-1,grid,dp);
    int temp2=grid[m][n]+find(m+1,n,grid,dp);
    int temp3=grid[m][n]+find(m+1,n+1,grid,dp);
    return dp[m][n]=min({temp1,temp2,temp3});
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) return matrix[0][0];
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int temp=1e9;
        for(int i=0;i<n;i++){
            temp=min(temp,find(0,i,matrix,dp));
        }
        // return temp;
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int temp1=dp[i+1][j];
                int temp2=(j>0)?dp[i+1][j-1]:1e9;
                int temp3=(j<n-1)?dp[i+1][j+1]:1e9;
                dp[i][j] = matrix[i][j] + min({temp1,temp2,temp3});
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[0][i]);
        }
        // return ans;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };

    int numPaths = solution.minFallingPathSum(matrix);
    cout << numPaths << endl;

    return 0;
}