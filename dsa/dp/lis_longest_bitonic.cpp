//increases and then decreases
//could be either completely increasing or decreasing
#include<bits/stdc++.h>
using namespace std;
int longestBitonicSubsequence(vector<int>& nums, int n)
{
	// Write your code here.
	 // code here
         vector<int>dp(n+1,1);
         int maxi=0;
         for(int i=1;i<n;i++){
          for(int j=0;j<i;j++){
               if(nums[i]>nums[j]&&dp[i]<1+dp[j]){
                dp[i]=1+dp[j];
                   }
                }
           
           }
           
           
           vector<int>dp2(n+1,1);
        //  int maxi=0;
         for(int i=n-1;i>=0;i--){
          for(int j=n-1;j>i;j--){
               if(nums[i]>nums[j]&&dp2[i]<1+dp2[j]){
                dp2[i]=1+dp2[j];
                   }
                }

           }
           int ans=0;
           for(int i=0;i<n;i++){
               ans=max(ans,dp[i]+dp2[i]-1);
           }
           return ans;
}
int main(){
    vector<int>nums={1,2,3,4,5,6,7,8,7,6,5,4,3,2,1};
    cout<<longestBitonicSubsequence(nums,nums.size())<<endl;
    return 0;
}