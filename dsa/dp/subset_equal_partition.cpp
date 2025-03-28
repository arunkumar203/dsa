#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool find(int sum,vector<int>&nums,int n,vector<vector<int>>&dp) {
        if (sum==0) return true;
        if (n==0) return nums[0]==sum;
        if (dp[n][sum]!=-1) return dp[n][sum];
        bool notTake=find(sum,nums,n-1,dp);
        bool take = false;
        if (nums[n]<=sum) {
            take=find(sum-nums[n],nums,n-1,dp);
        }
        return dp[n][sum]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums) {
            sum+=i;
        }
        if(sum%2!=0) return false;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));       
        return find(sum/2,nums,n-1,dp);
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 5, 11, 5};
    cout << solution.canPartition(nums) << endl;
    return 0;
}