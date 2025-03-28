//368
//Given a set of distinct positive integers nums, return the largest subset answer such 
//that every pair (answer[i], answer[j]) of elements in this subset satisfies:
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
            vector<int>dp(n+1,1);
    vector<int>hash(n);
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        hash[i]=i;
    }
    int maxi=0;//stores last ind
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0&&dp[i]<1+dp[j]){
                dp[i]=1+dp[j];
                hash[i]=j;               
            }
        }
        if(dp[maxi]<dp[i]){
                maxi=i;
            }
    }
    // int temp=*max_element(dp.begin(),dp.end());
    vector<int>ans;
    ans.push_back(nums[maxi]);
    while(maxi!=hash[maxi]){
        maxi=hash[maxi];
        ans.push_back(nums[maxi]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};
int main(){
    vector<int>nums={1,2,3};
    Solution obj;
    vector<int>ans=obj.largestDivisibleSubset(nums);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}