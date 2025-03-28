//2560
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
    int find(vector<int>&nums,int i,int k,vector<vector<int>>&dp){
        int n=nums.size();
        if(k==0) return 0;
        if(i>=n) return INT_MAX;
        if(dp[i][k]!=-1) return dp[i][k];
        int take=max(nums[i],find(nums,i+2,k-1,dp));
        int nott=find(nums,i+1,k,dp);
        return dp[i][k]=min(take,nott);
    }
    
    
    int minCapability1(vector<int>& nums, int k){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return find(nums,0,k,dp);
    }
    
    
    bool canrob(vector<int>&nums,int m, int k){
        int count=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=m){
                count++;
                i++;
            }
        }
        return count>=k;
    }
        int minCapability(vector<int>& nums, int k) {
            int s=1,e=*max_element(nums.begin(),nums.end());
            int ans=0;
            while(s<=e){
                int m=s+(e-s)/2;
                if(canrob(nums,m,k)){
                    e=m-1;
                }
                else{
                    s=m+1;
                }
            }
            return s;
    
        }
    };
    
int main(){
    Solution s;
    vector<int>nums={2,3,5,9};
    int k=2;
    cout<<s.minCapability(nums,k)<<endl;
    return 0;
}
