#include <bits/stdc++.h>
using namespace std;
bool find(vector<int>&a,int n,int target,vector<vector<int>>&dp){
    if(target==0) return true;
    if(n==0) return a[0]==target;
    if(dp[n][target]!=-1) return dp[n][target];
    bool not_take=find(a,n-1,target,dp);
    bool take=false;
    if(a[n]<=target)  take=find(a,n-1,target-a[n],dp);    
    return dp[n][target]=take||not_take;
}

int main() {
    vector<int> nums = {8,6,5};
    int k=0;
    int n=nums.size();
    for(auto i:nums) k+=i;
    // cout<<k<<endl;
    vector<vector<int>>dp(n,vector<int>(k+1,false));
    for(int i=0;i<=k;i++){
        bool temp=find(nums,n-1,i,dp);
    }
    // bool temp=find(nums,n-1,k,dp);//this condition doesnt fill all dp values
    // for(int i=0;i<n;i++){
    //     dp[i][0]=true;
    // }
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<=k;j++){
    //         if(nums[i]>j) dp[i][j]=dp[i-1][j];
    //         else dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i]];
    //     }
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int ans=INT_MAX;
    for(int i=0;i<=k/2;i++){
        if(dp[n-1][i]){
            ans=min(ans,abs(k-2*i));
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
