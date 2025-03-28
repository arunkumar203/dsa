#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1), count(n, 1);

        int maxi = 1; // initialize maxi to 1 since the minimum length of LIS is 1

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // start a new LIS ending at i
                    } else if (dp[i] == dp[j] + 1) {
                        count[i] += count[j]; // extend existing LIS ending at i
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                ans += count[i];
            }
        }
        return ans;
    }
};

int main(){
    vector<int>nums={1,3,5,4,7};
    Solution s;
    cout<<s.findNumberOfLIS(nums)<<endl;
    return 0;
}