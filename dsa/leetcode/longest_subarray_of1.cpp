//1493
//return length of longest subarray of 1's after deleting one element

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int n=nums.size();
            int l=0;
            int zero=0;
            int ans=0;
            for(int r=0;r<n;r++){
                if(nums[r]==0){
                    zero++;
                }
                while(zero>1){
                    if(nums[l]==0) zero--;
                    l++;
                }
                ans=max(ans,r-l);
            }
            return ans;
        }
    };
int main(){
    vector<int>nums={1,1,0,0,1,1,1,0,1};
    Solution ss;
    cout<<ss.longestSubarray(nums)<<endl;
}