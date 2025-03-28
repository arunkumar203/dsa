//410
// that the largest sum of any subarray is minimized.
//mid defines that max sum
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool ispossible(vector<int>&nums,int n,int k,int mid){
        int temp=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                temp++;
                if(temp>k || nums[i]>mid) return false;
                sum=nums[i];
            }
    
        }
        return true;
    }
        int splitArray(vector<int>& nums, int k) {
            int n=nums.size();
            int s=0;
            int ans=0;
            int e=accumulate(nums.begin(),nums.end(),0);
            while(s<=e){
                int mid=s+(e-s)/2;
                if(ispossible(nums,n,k,mid)){
                    ans=mid;
                    e=mid-1;
                }
                else s=mid+1;
            }
            return ans;
        }
    };
    
int main() {
    Solution s;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    int ans = s.splitArray(nums, k);
    cout << "Minimum largest sum: " << ans << endl;
    return 0;
}
