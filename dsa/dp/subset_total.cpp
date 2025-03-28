//total subsets
#include<bits/stdc++.h>
using namespace std;
int find(vector<int>&a,int n,int target,vector<vector<int>>&dp){
    if(target==0) return 1;
    if (n < 0) return 0;
    if(n==0) return a[0]==target;
    if(dp[n][target]!=-1) return dp[n][target];
    int not_take=find(a,n-1,target,dp);
    int take=false;
    if(a[n]<=target)  take=find(a,n-1,target-a[n],dp);    
    return dp[n][target]=take+not_take;
}
int main(){
    vector<int>a={2,3,1,1};
    int n=a.size();
    int target=4;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<find(a,n-1,target,dp)<<endl;
    // cout<<bottomup(a,n,target)<<endl;
    
}