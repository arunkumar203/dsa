//i,prev
//i is from 0 to n-1 ans prev is from -1 to n-1 so we shift prev by 1
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int find(vector<int>&nums,int i,int prev,int n,vector<vector<int>>&dp){
    if(i==n) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int nott=find(nums,i+1,prev,n,dp);
    int take=INT_MIN;
    if(prev==-1||nums[i]>nums[prev]) take=find(nums,i+1,i,n,dp)+1;
    return dp[i][prev+1] =max(take,nott);
}
int find2(vector<int>&nums,int n){
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            int len=dp[i+1][j+1];
            if(j==-1||nums[i]>nums[j]){
               len=max(len,1+dp[i+1][i+1]);
            }    
           dp[i][j+1]=len;
        }
    }
    return dp[0][0];
}
int find3(vector<int>&nums,int n){
    vector<int>dp(n+1,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return find(nums,0,-1,n,dp);
        // return find2(nums,n);
        return find3(nums,n);
    }
};
int main(){
    vector<int>nums={10,9,2,5,3,7,101,18};
    Solution obj;
    cout<<obj.lengthOfLIS(nums)<<endl;
    return 0;
}