#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(n<0) return INT_MAX;
        if(amount==0) return 0;//0 coins are req when amount=0
        if(dp[n][amount]!=-1) return dp[n][amount];       
        int nottake=find(n-1,coins,amount,dp);
        int take=INT_MAX;
        if(amount>=coins[n]) {
            int res=find(n,coins,amount-coins[n],dp);
            if (res!=INT_MAX) take=1+res;
        }
        return dp[n][amount]=min(nottake, take);
    }
int find2(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
    for(int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= amount; j++) {
            if (i > 0) {
                dp[i][j] = dp[i-1][j];//not take
            }
            if (j >= coins[i] && dp[i][j-coins[i]] != INT_MAX) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j-coins[i]]);
            }
        }
    }

    return (dp[n-1][amount] == INT_MAX) ? -1 : dp[n-1][amount];
}

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int temp= find(n-1,coins,amount,dp);
        return (temp==INT_MAX)?-1:temp;
    }
};
int main(){
    vector<int>coins={1,2,5};
    int amount=11;
    Solution s;
    cout<<s.coinChange(coins,amount)<<endl;
    cout<<s.find2(coins,amount)<<endl;
}
