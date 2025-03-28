//1004
//nums with o,1 can flip atmost k 0's,return maxlength of continuous subarray of 1s
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n=nums.size();
            int i=0,j=0;
            int ans=0;
            while(j<n){
                if(nums[j]==0) k--;
                while(k<0){
                    if(nums[i]==0) k++;
                    i++;
                }
                ans=max(ans,j-i+1);
                j++;
            }
            return ans;
        }
    };
    int main(){
        Solution s;
        vector<int>nums={1,1,1,0,0,0,1,1,1,1,0};
        int k=2;
        cout<<s.longestOnes(nums,k)<<endl;
    }