#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int find(int i,int j,string s,string t,vector<vector<int>>&dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) return dp[i][j]=find(i-1,j-1,s,t,dp)+find(i-1,j,s,t,dp);
     return dp[i][j]=find(i-1,j,s,t,dp);
}
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return find(m-1,n-1,s,t,dp);
        vector<double>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=m;i++){
            for(int j=n;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    dp[j]=dp[j-1]+dp[j];
                }
            }
        }
        return (int)dp[n];

    }
};
int main(){
    string s1="rabbbit";
    string s2="rabbit";
    Solution s;
    cout<<s.numDistinct(s1,s2)<<endl;
    return 0;
}