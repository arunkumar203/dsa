//188
//at most k transactions
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int find(vector<int>&prices,int i,int buy,int n,vector<vector<vector<int>>>&dp,int cap){
    if(i==n|| cap==0) return 0;
    int ans=0;
    if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
    if(buy==0){//is previously bought
       ans=max(find(prices,i+1,0,n,dp,cap),-prices[i]+find(prices,i+1,1,n,dp,cap));
    }
    if(buy==1){
        ans=max(find(prices,i+1,1,n,dp,cap),prices[i]+find(prices,i+1,0,n,dp,cap-1));
    }
    return dp[i][buy][cap]=ans;
}
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return find(prices,0,0,n,dp,k);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 0; cap <= k; cap++) {//gives same ans even if cap is  iterated from 1
                    if (buy == 0) {
                        dp[i][buy][cap] = max(dp[i + 1][0][cap], -prices[i] + dp[i + 1][1][cap]);
                    } else {
                        dp[i][buy][cap] = max(dp[i + 1][1][cap], prices[i] + dp[i + 1][0][cap - 1]);
                    }
                }
            }
        }

        return dp[0][0][k];
    }
};
int main(){
    vector<int>prices={3,2,6,5,0,3};
    Solution obj;
    cout<<obj.maxProfit(2,prices)<<endl;
    return 0;
}