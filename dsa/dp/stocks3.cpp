//123
//buy atmost 2 times
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
int find2(vector<int>& prices, int i, int trans, int n, vector<vector<int>>& dp) {
        if (i == n || trans == 4) return 0; // 4 transactions cover both buy and sell twice
        if (dp[i][trans] != -1) return dp[i][trans];
        
        int ans = 0;
        if (trans % 2 == 0) { // buy state
            ans = max(find2(prices, i + 1, trans, n, dp), -prices[i] + find2(prices, i + 1, trans + 1, n, dp));
        } else { // sell state
            ans = max(find2(prices, i + 1, trans, n, dp), prices[i] + find2(prices, i + 1, trans + 1, n, dp));
        }
        
        return dp[i][trans] = ans;
    }
    int find3(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0)); // 5 transaction states (0 to 4)

        // Process days from the end to the beginning
        for (int i = n - 1; i >= 0; i--) {
            for (int trans = 0; trans < 4; trans++) {
                if (trans % 2 == 0) { // buy state
                    dp[i][trans] = max(dp[i + 1][trans], -prices[i] + dp[i + 1][trans + 1]);
                } else { // sell state
                    dp[i][trans] = max(dp[i + 1][trans], prices[i] + dp[i + 1][trans + 1]);
                }
            }
        }

        return dp[0][0]; // Start at day 0 with 0 transactions
    }
    int find4(vector<int>&prices){
          int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 0) {
                        dp[i][buy][cap] = max(dp[i + 1][0][cap], -prices[i] + dp[i + 1][1][cap]);
                    } else {
                        dp[i][buy][cap] = max(dp[i + 1][1][cap], prices[i] + dp[i + 1][0][cap - 1]);
                    }
                }
            }
        }

        return dp[0][0][2];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp1(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        cout<< find(prices,0,0,n,dp1,2)<<endl;

        // vector<vector<int>> dp(n, vector<int>((2*2)+1, -1));
        // return find2(prices,0,0,n,dp);
        return find3(prices);

       
    }
};
int main(){
    vector<int>prices={3,3,5,0,0,3,1,4};
    Solution obj;
    cout<<obj.maxProfit(prices)<<endl;
    return 0;
}

