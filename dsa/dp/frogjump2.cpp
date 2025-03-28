#include<bits/stdc++.h>
using namespace std;
int find(vector<int>& dp, vector<int>& heights, int n, int k) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int ans = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (n - i >= 0) {
            int temp = find(dp, heights, n - i, k) + abs(heights[n] - heights[n - i]);
            ans = min(temp, ans);
        }
    }
    return dp[n-1] = ans;
    //time=O(n)*k
}

int minimizeCost(int n, int k, vector<int>& height) {
    vector<int> dp(n + 1, -1);
    return find(dp, height, n, k);
    // dp[0]=0;
    // for(int i=1;i<n;i++){
    //     int ans=INT_MAX;

    //     for(int j=1;j<=k;j++){
    //         if(i-j>=0){
    //             int jump=dp[i-j]+abs(height[i]-height[i-j]);
    //              ans=min(ans,jump);

    //         }
    //     }
    //     dp[i]=ans;
    // }
    // return dp[n-1];
}
int main(){
    int n=5,k=3;
    vector<int>height={30,10,60,10,60};
    cout<<minimizeCost(n,k,height)<<endl;
    return 0;
}