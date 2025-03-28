#include <bits/stdc++.h> 
using namespace std;

int find(vector<int>& heights, vector<int>& dp, int n) {
    dp[0] = 0;
    int right = INT_MAX;
    for(int i = 1; i < n; i++) {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        if(i > 1)
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(left, right);
    }
    return dp[n - 1];

    //time=O(n);
}

int frogJump(int n, vector<int>& heights) {
    vector<int> dp(n + 1, -1);
    return find(heights, dp, n);
}
int main() {
    // Your code here
    int n = 5;
    vector<int> heights = {30, 10, 60, 10, 60};
    cout << frogJump(n, heights) << endl;

    return 0;
}
