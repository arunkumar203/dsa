#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestSubarrayWithSumK(const vector<int>& nums, int k) {
    unordered_map<int, int> firstOccurrence; // stores prefix sum -> earliest index
    int sum = 0;
    int maxLen = 0;
    
    // Handle the base case: if a subarray from index 0 sums to k
    firstOccurrence[0] = -1; 
    
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        
        // If this prefix sum hasn't been seen before, store its index
        if (firstOccurrence.find(sum) == firstOccurrence.end()) {
            firstOccurrence[sum] = i;
        }
        
        // If there exists a prefix sum equal to (sum - k),
        // then the subarray from the first occurrence of (sum-k) + 1 to i sums to k.
        if (firstOccurrence.find(sum - k) != firstOccurrence.end()) {
            maxLen = max(maxLen, i - firstOccurrence[sum - k]);
        }
    }
    
    return maxLen;
}

int main(){
    // Example test case: can contain positive, negative, and 0's.
    vector<int> nums = {1, -1, 5, -2, 3};  // Longest subarray with sum 3 is from index 0 to 4
    int k = 3;
    
    cout << "Longest subarray length with sum " << k << " is: " 
         << longestSubarrayWithSumK(nums, k) << endl;
    return 0;
}


//if no -ve then optimal would be sliding window
// class Solution {
//     public:
//         int longestSubarray(vector<int>& nums, int k) {
//             int n = nums.size();
//             int i = 0, sum = 0, maxLen = 0;
            
//             // Expand the window using j.
//             for (int j = 0; j < n; j++) {
//                 sum += nums[j];
                
//                 // Shrink the window from the left while sum > k.
//                 while (i <= j && sum > k) {
//                     sum -= nums[i];
//                     i++;
//                 }
                
//                 // When the current window sums to k, update maxLen.
//                 if (sum == k) {
//                     maxLen = max(maxLen, j - i + 1);
//                 }
//             }
            
//             return maxLen;
//         }
//     };
    