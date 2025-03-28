//53
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int cs = 0;          
            int ms = INT_MIN;     
            
            for (int i = 0; i < nums.size(); i++) {
                cs+=nums[i];
                if(cs>ms) ms=cs;
                if(cs<0) cs=0;            
            }
    
            return ms;
            
        }
    };
    int main(){
        Solution s;
        vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
        cout<<s.maxSubArray(nums)<<endl;
    }