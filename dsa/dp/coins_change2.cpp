//518
//in coin change 1 we need min coins to make the amount
//in coin change 2 we need number of ways to make the amount
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(amount==0) return 1;
        if(n<0) return 0;
        if(dp[n][amount]!=-1) return dp[n][amount];       
        int nottake=find(n-1,coins,amount,dp);
        int take=0;
        if(amount>=coins[n]) {
             take=find(n,coins,amount-coins[n],dp);
        }
        return dp[n][amount]=(nottake+ take);
    }
    int change(int amount, vector<int>& coins) {
        // int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // int temp= find(n-1,coins,amount,dp);
        // return (temp==INT_MAX)?-1:temp;

        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for (int i=0;i<=n;i++) dp[i][0]=1;
        for (int i=0;i<n;i++) {
            for (int j=1;j<=amount;j++) {
                if(i>0) dp[i][j]=dp[i-1][j];
                if (j>=coins[i]) {
                    dp[i][j]+=dp[i][j-coins[i]]; 
                }
            }
        }
        return dp[n-1][amount];
    }
};
int main(){
    vector<int>coins={1,2,5};
    int amount=5;
    Solution s;
    cout<<s.change(amount,coins)<<endl;
}