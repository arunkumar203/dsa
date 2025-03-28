#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int find(vector<int>&prices,int i,int buy,int n,vector<vector<int>>&dp,int fee){
    if(i==n) return 0;
    int ans=0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy==0){//is previously bought
       ans=max(find(prices,i+1,0,n,dp,fee),-prices[i]+find(prices,i+1,1,n,dp,fee));
    }
    if(buy==1){
        ans=max(find(prices,i+1,1,n,dp,fee),-fee+prices[i]+find(prices,i+1,0,n,dp,fee));
    }
    return dp[i][buy]=ans;
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return find(prices,0,0,n,dp,fee);
    }
};
int main(){
    vector<int>prices={1,3,2,8,4,9};
    Solution obj;
    cout<<obj.maxProfit(prices,2)<<endl;
    return 0;
}