//309
//cooldown period of 1 just after selling
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int find1(vector<int>&prices,int i,int buy,int n,vector<vector<int>>&dp,bool cooldown){
    if(i==n) return 0;
    int ans=0;
    if(!cooldown&&dp[i][buy]!=-1) return dp[i][buy];
    if(cooldown==true) return find1(prices,i+1,0,n,dp,false);
    if(buy==0){//is previously bought
       ans=max(find1(prices,i+1,0,n,dp,false),-prices[i]+find1(prices,i+1,1,n,dp,false));
    }
    if(buy==1){
        ans=max(find1(prices,i+1,1,n,dp,false),prices[i]+find1(prices,i+1,0,n,dp,true));
    }
    if(!cooldown) dp[i][buy]=ans;
    return ans;
}
int find2(vector<int>&prices,int i,int buy,int n,vector<vector<int>>&dp){
    if(i>=n) return 0;
    int ans=0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy==0){//is previously bought
       ans=max(find2(prices,i+1,0,n,dp),-prices[i]+find2(prices,i+1,1,n,dp));
    }
    if(buy==1){
        ans=max(find2(prices,i+1,1,n,dp),prices[i]+find2(prices,i+2,0,n,dp));
    }
     return dp[i][buy]=ans;
   
}
int find3(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = 0;
    dp[n][1] = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] + prices[i]);
        dp[i][1] = max(dp[i + 1][1], dp[i + 2][0] - prices[i]);
    }
    return dp[0][0];
}

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        bool cooldown=false;
        // return find1(prices,0,0,n,dp,cooldown);
        // return find2(prices,0,0,n,dp);
        return find3(prices);

    }
};
int main(){
    vector<int>prices={1,2,3,0,2};
    Solution obj;
    cout<<obj.maxProfit(prices)<<endl;
    return 0;
}

