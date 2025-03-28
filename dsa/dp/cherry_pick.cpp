#include<bits/stdc++.h>
using namespace std;
//2 people start at 0,0 and 0,n-1 move till last row &try to collect max cherries
//if have same cell then only 1 person can collect
//at every time they will be in same row
class Solution {
public:
    int find(int i,int j1,int j2,int m,int n,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp) {
        if(j1<0||j2<0||j1>n-1||j2>n-1) return -1e9;
        if(i==m-1){
            if (j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];        
        int maxi=-1e9;
        for(int dj1=-1;dj1<=1;dj1++) {
            for(int dj2=-1;dj2<=1;dj2++) {
                int temp=(j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
                temp+=find(i+1,j1+dj1,j2+dj2,m,n,grid,dp);
                maxi=max(maxi,temp);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return find(0,0,n-1,m,n,grid,dp);
    }
};
//[[8,8,10,9,1,7],[8,8,1,8,4,7],[8,6,10,3,7,7],[3,0,9,3,2,7],[6,8,9,4,2,5],[1,1,5,8,8,1],[5,6,5,2,9,9],[4,4,6,2,5,4],[4,4,5,3,1,6],[9,2,2,1,9,3]]
int main() {
    Solution solution;
    vector<vector<int>>grid={{8,8,10,9,1,7},{8,8,1,8,4,7},{8,6,10,3,7,7},{3,0,9,3,2,7},{6,8,9,4,2,5},{1,1,5,8,8,1},{5,6,5,2,9,9},{4,4,6,2,5,4},{4,4,5,3,1,6},{9,2,2,1,9,3}}; 

    int numPaths = solution.cherryPickup(grid);
    cout << numPaths << endl;

    return 0;
}