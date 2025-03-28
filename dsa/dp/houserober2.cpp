#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& nums, int n, vector<int>& dp) {
    if (n == 0) return nums[0];
    if(n<0) return 0;
    if (dp[n] != -1) return dp[n];
    int pick = nums[n] + find(nums, n - 2, dp);
    int notpick = find(nums, n - 1, dp);
    return dp[n] = max(pick, notpick);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp1(n + 1, -1),dp2(n+1,-1);
    vector<int>nums1,nums2;
    if(n==1) return nums[0];
    for(int i=0;i<nums.size();i++){
        if(i!=0) nums1.push_back(nums[i]);
        if(i!=nums.size()) nums2.push_back(nums[i]);
    }

    return max(find(nums1, n - 2, dp1),find(nums2,n-2,dp2));
}

int main() {
    // Test your code here
    vector<int> nums = {1,2,3,1};
    cout << rob(nums) << endl;
    return 0;
}


//tabulation
#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    vector<int> dp1(n + 1, 0),dp2(n+1,0);
    vector<int>nums1,nums2;
    for(int i=0;i<nums.size();i++){
        if(i!=0) nums1.push_back(nums[i]);
        if(i!=nums.size()-1) nums2.push_back(nums[i]);
    }
    dp1[1] = nums[0];
    dp2[1] = nums[n-1];
    for(int i=2;i<=n;i++){
        dp1[i] = max(dp1[i-1],dp1[i-2]+nums1[i-2]);
        dp2[i] = max(dp2[i-1],dp2[i-2]+nums2[i-2]);
    }
    return max(dp1[n],dp2[n]);
}

int main() {
    // test your function here
    vector<int> nums = {1,2,3,1};
    cout << rob(nums) << endl;
    return 0;
}












