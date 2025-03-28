//122
//buy and sell multiple times
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int find(vector<int>&prices,int i,int buy,int n,vector<vector<int>>&dp){
    if(i==n) return 0;
    int ans=0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy==0){//is previously bought
       ans=max(find(prices,i+1,0,n,dp),-prices[i]+find(prices,i+1,1,n,dp));
    }
    if(buy==1){
        ans=max(find(prices,i+1,1,n,dp),prices[i]+find(prices,i+1,0,n,dp));
    }
    return dp[i][buy]=ans;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return find(prices,0,0,n,dp);
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==0){
                    dp[i][j]=max(dp[i+1][0],-prices[i]+dp[i+1][1]);
                }
                if(j==1){
                    dp[i][j]=max(dp[i+1][1],prices[i]+dp[i+1][0]);
                }
            }
        }
        return dp[0][0];
    }
};
int main(){
    vector<int>prices={7,1,5,3,6,4};
    Solution obj;
    cout<<obj.maxProfit(prices)<<endl;
    return 0;
}