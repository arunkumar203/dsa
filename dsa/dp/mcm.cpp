#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
// int find(int i,int j,int nums[],vector<vector<int>>&dp){
//     if(i==j) return 0;
//     int mini=1e9;
//     if(dp[i][j]!=-1) return dp[i][j];
//     for(int k=i;k<=j-1;k++){
//         int steps=nums[i-1]*nums[k]*nums[j]+find(i,k,nums,dp)+find(k+1,j,nums,dp);
//         if(steps<mini) mini=steps;
//     }
//     return dp[i][j]=mini;
// }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        // vector<vector<int>>dp(N,vector<int>(N,-1));
        // return find(1,N-1,arr,dp);
        int dp[n][n];
        for(int i=1;i<n;i++) dp[i][i]=0;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<=n-1;j++){
                int mini=1e9;
                for(int k=i;k<=j-1;k++){
                    int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    if(steps<mini) mini=steps;
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][n-1];
    }
};
int main(){
    int n=4;
    int arr[]={10, 30 ,5, 60};
    Solution s;
    cout<<s.matrixMultiplication(n,arr)<<endl;
    return 0;
}