//insert,remove,replace
#include<bits/stdc++.h>
using namespace std;
int find(int m,int n,string s1,string s2,vector<vector<int>>&dp){
    if(m<0) return n+1;
    if(n<0) return m+1;
    if(dp[m][n]!=-1) return dp[m][n];
    if(s1[m]==s2[n]) return dp[m][n]=find(m-1,n-1,s1,s2,dp);
    return dp[m][n]=1+min({find(m-1,n,s1,s2,dp),find(m,n-1,s1,s2,dp),find(m-1,n-1,s1,s2,dp)});
}
int find2(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) {
        // dp[i][0] = i; // Requires i deletions to convert s1[0..i-1] to empty string
    }
    for (int j = 0; j <= n; j++) {
        // dp[0][j] = j; // Requires j insertions to convert empty string to s2[0..j-1]
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; 
            } else {
                dp[i][j] = min({
                    dp[i - 1][j] + 1, 
                    dp[i][j - 1] + 1, 
                    dp[i - 1][j - 1] + 1 
                });
            }
        }
    }
    return dp[m][n];
}
int main(){
    string s1="sunday";
    string s2="saturday";
    vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
    cout<<find(s1.size()-1,s2.size()-1,s1,s2,dp)<<endl;
    cout<<find2(s1,s2)<<endl;
    return 0;
}