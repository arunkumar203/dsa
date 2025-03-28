#include<bits/stdc++.h>
using namespace std;
bool find(vector<int>&a,int n,int target,vector<vector<int>>&dp){
    if(target==0) return true;
    if (n < 0) return false;
    if(n==0) return a[0]==target;
    if(dp[n][target]!=-1) return dp[n][target];
    bool not_take=find(a,n-1,target,dp);
    bool take=false;
    if(a[n]<=target)  take=find(a,n-1,target-a[n],dp);    
    return dp[n][target]=take||not_take;
}


bool bottomup(vector<int>&a,int n,int target){
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            if(a[i]>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i]];
        }
    }
    return dp[n-1][target];
}
int main(){
    vector<int>a={2,3,1,1};
    int n=a.size();
    int target=4;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<find(a,n-1,target,dp)<<endl;
    // cout<<bottomup(a,n,target)<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<=target;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}