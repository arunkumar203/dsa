#include <bits/stdc++.h>
using namespace std;
//single row optimized space
int find(int w, int n, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (n < 0) return 0; 
    if (dp[n][w] != -1) return dp[n][w];  
    int not_take = find(w, n - 1, wt, val, dp);
    int take = 0;
    if (wt[n] <= w) {
        take = val[n] + find(w - wt[n], n - 1, wt, val, dp);
    }
    return dp[n][w] = max(take, not_take);
}
int find2(int w,int n,vector<int>&wt,vector<int>&val){
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(wt[i-1]<=j) dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}
int find3(int w,int n,vector<int>&wt,vector<int>&val){
    // vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    vector<int>dp(w+1,0);
    vector<int>prev(w+1,0);
    vector<int>curr(w+1,0);
    //converted for 1 base indexing
    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(wt[i-1]<=j) curr[j]=max(prev[j],val[i-1]+prev[j-wt[i-1]]);
            else prev[j]=prev[j];
        }
        prev=curr;
    }
    return curr[w];
}
int find4(int w, int n, vector<int>& wt, vector<int>& val) {
    vector<int> dp(w + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= 0; j--) {
            if (wt[i-1] <= j) {
                dp[j] = max(dp[j], val[i-1] + dp[j - wt[i-1]]);
            }
        }
    }
    
    return dp[w];
}

int main() { 
    int W = 10;
    vector<int> wt = {2, 3, 4, 5};
    vector<int> val = {3, 4, 5, 6};
    int n = wt.size();
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    int max_value = find(W,n-1, wt, val,dp);
    int max_value2 = find2(W,n, wt, val);
    cout << "Maximum value: " << max_value << endl;
    cout << "Maximum value: " << max_value2 << endl;
    cout<<find3(W,n,wt,val)<<endl;
    cout<<find4(W,n,wt,val)<<endl;

    return 0;
}