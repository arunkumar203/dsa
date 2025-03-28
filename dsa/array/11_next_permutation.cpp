//31
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            int idx = -1;
            
            // Step 1: Find the first decreasing element from the right
            for (int i = n - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    idx = i;
                    break;
                }
            }
            
            // Step 2: If no such element found, reverse the whole array
            if (idx == -1) {
                reverse(nums.begin(), nums.end());
                return;  // Done, no further steps needed
            }
            
            // Step 3: Find the rightmost element greater than nums[idx]
            for (int i = n - 1; i > idx; i--) {
                if (nums[i] > nums[idx]) {
                    swap(nums[i], nums[idx]);
                    break;  // Swap with the rightmost greater element
                }
            }
            
            // Step 4: Reverse the suffix starting from idx + 1
            reverse(nums.begin() + idx + 1, nums.end());
        }
    };
    int main(){
        Solution s;
        vector<int>nums={1,2,3};
        s.nextPermutation(nums);
        for(auto i:nums){
            cout<<i<<" ";
        }
        cout<<endl;
    }