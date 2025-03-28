//diff btwn 2 subsets is d;
#include<bits/stdc++.h>
using namespace std;
int mod=int(1e9+7);
int find(vector<int>&a,int n,int target,vector<vector<int>>&dp){
    // if(target==0) return 1;
    if(n==0){
        if(target==0&&a[n]==0) return 2;
        if(target==0||target==a[n]) return 1;
        return 0;
    }
    if (n < 0) return 0;
    if(n==0) return a[0]==target;
    if(dp[n][target]!=-1) return dp[n][target];
    int not_take=find(a,n-1,target,dp);
    int take=false;
    if(a[n]<=target)  take=find(a,n-1,target-a[n],dp);    
    return dp[n][target]=(take+not_take)%mod;
}
    int countPartitions(int n, int d, vector<int>& nums) {
        int s=0;
        for(auto i:nums) s+=i;
        vector<vector<int>>dp(n,vector<int>(s+1,-1));
        if(s-d<0||(s-d)%2) return false;
      return find(nums,n-1,(s-d)/2,dp);
    }

int main(){
    vector<int>nums={1,2,3,4,5};
    int n=nums.size();
    int d=1;
    cout<<countPartitions(n,d,nums)<<endl;
}