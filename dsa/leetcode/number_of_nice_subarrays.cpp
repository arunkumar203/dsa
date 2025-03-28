#include<bits/stdc++.h>
using namespace std;
//  A subarray is called nice if there are k odd numbers in it
class Solution {
public:
   int find(vector<int>&nums,int k){ //function to find number of subarrays with sum<=k
    if(k<0) return 0;
    int i=0,j=0,sum=0,temp=0;
    while(j<nums.size()){
        sum+=nums[j];
        while(sum>k){
            sum-=nums[i];
            i++;
        }
        temp+=j-i+1;
        j++;
    }
    return temp;
   }
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>num;
        for(auto i:nums){
            num.push_back(i%2);
        }
       return find(num,k)-find(num,k-1);
    }
};
int main() {
    // Test the Solution class
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 1, 2, 1, 1};
    int k1 = 3;
    int result1 = solution.numberOfSubarrays(nums1, k1);
    cout << "Result 1: " << result1 << endl;
    
    // Test case 2
    vector<int> nums2 = {2, 4, 6};
    int k2 = 1;
    int result2 = solution.numberOfSubarrays(nums2, k2);
    cout << "Result 2: " << result2 << endl;
    
    // Test case 3
    vector<int> nums3 = {1, 2, 3, 4, 5};
    int k3 = 2;
    int result3 = solution.numberOfSubarrays(nums3, k3);
    cout << "Result 3: " << result3 << endl;
    
    return 0;
}