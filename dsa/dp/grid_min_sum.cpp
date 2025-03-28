#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 int   find1(int m, int n, vector<vector<int>>& dp,vector<vector<int>>&grid) {
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) dp[i][j]=grid[0][0];
                //if we dont use the below condition then dp[0][0]is set to 1e9+grid[i][j]
                //which continues to a starting error and flows till end
                else{
                    int temp1=1e9,temp2=1e9;
                    if(i>0)  temp1=dp[i-1][j];
                    if(j>0)  temp2=dp[i][j-1];
                    dp[i][j]=grid[i][j]+min(temp1,temp2);
                }
                
            }
        }
        return dp[m-1][n-1];
    }
    int   find2(int m, int n, vector<vector<int>>& dp,vector<vector<int>>&grid) {
    if(m==0&&n==0) return grid[0][0];
    if(m<0||n<0) return 1e9; 
    //if we return 0,it means dp[m][n] is set to 0 and the error flows,so if we set it to higher value 
    //then it will not be considered in the minimum value
    //it is basically the imaginary cell(-ve indexed) is created for the min path
    //1  3  1
    //1  5  1
    //4  2  1
    if(dp[m][n]!=-1) return dp[m][n];
    int temp1=find2(m-1,n,dp,grid);
    int temp2=find2(m,n-1,dp,grid);
    return dp[m][n]=min(temp1,temp2)+grid[m][n];
}

    int minPathSum(vector<vector<int>>grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return find1(m,n,dp,grid);
        return find2(m-1,n-1,dp,grid);
    }
};
int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    int numPaths = solution.minPathSum(grid);
    cout << numPaths << endl;

    return 0;
}