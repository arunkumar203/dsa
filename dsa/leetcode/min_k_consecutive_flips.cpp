#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int flipcount=0;
        vector<bool>isflipped(n,false);
        for(int i=0;i<n;i++){
            if(i>=k && isflipped[i-k]==true){
                flipcount--;
            }
            if(flipcount%2==nums[i]){
                if(i+k>n){
                    return -1;
                }
                flipcount++;
                ans++;
                isflipped[i]=true;
            }
        }
        return ans;
    }
};
int main() {
    // Test the minKBitFlips function
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {0, 1, 0, 0, 1, 0};
    int k1 = 3;
    int result1 = solution.minKBitFlips(nums1, k1);
    cout << "Result 1: " << result1 << endl;
    
    // Test case 2
    vector<int> nums2 = {1, 1, 0, 1, 1};
    int k2 = 2;
    int result2 = solution.minKBitFlips(nums2, k2);
    cout << "Result 2: " << result2 << endl;
    
    return 0;
}