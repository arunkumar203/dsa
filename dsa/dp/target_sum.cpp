//494
//given target sum ,with nums, find the number of ways to get the target sum by assiging 
//+ or - to each element of nums
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(vector<int>& a,int n,int target,vector<vector<int>>&dp) {
        if(target<0) return 0; 
        if(n==0) {
            if(target==0&&a[0]==0) return 2;
            if(target==0||target==a[0]) return 1;
            return 0;
        }
        if (dp[n][target]!=-1) return dp[n][target];       
        int not_take=find(a,n-1,target,dp);
        int take=0;
        if (a[n] <= target) take=find(a,n-1,target-a[n],dp);       
        return dp[n][target]=take+not_take;
    }

    int countPartitions(int n,int d,vector<int>& nums) {
        int s=0;
        for(auto i:nums) s+=i;
        if(s<d||(s-d)%2!=0) return 0;
        int target=(s-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return find(nums,n-1,target,dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};
int main(){
    vector<int>nums={1,1,1,1,1};
    int target=3;
    Solution s;
    cout<<s.findTargetSumWays(nums,target)<<endl;
}