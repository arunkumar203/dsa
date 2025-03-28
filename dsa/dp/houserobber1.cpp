#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& nums, int n, vector<int>& dp) {
    if (n == 0) return nums[0];
    if(n<0) return 0;
    if (dp[n] != -1) return dp[n];
    //n-3 n-2 n-1 n
    int pick = nums[n] + find(nums, n - 2, dp);   
    int notpick = find(nums, n - 1, dp);
    return dp[n] = max(pick, notpick);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return find(nums, n - 1, dp);
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
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[n - 1];
}


int main() {
    // Test your code here
    vector<int> nums = {1,2,3,1};
    cout << rob(nums) << endl;
    return 0;
}

