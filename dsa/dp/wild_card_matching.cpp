//4
//match s with p(where p has chars, ? and *)
//? matches any single char, * matches any sequence of chars(can be of even 0 len)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isall(string &S1,int i) {
    for (int j=0;j<=i;j++) {
        if (S1[j]!='*')
            return false;
    }
    return true;
}
bool find(int m,int n,string s,string p,vector<vector<int>>&dp){
    if(m<0&&n<0) return true;
    if(n<0) return false;
    if(m<0) return isall(p,n);
    if(dp[m][n]!=-1) return dp[m][n];
    if(s[m]==p[n]||p[n]=='?') return find(m-1,n-1,s,p,dp);
    else{
        if(p[n]=='*'){
            return dp[m][n]=find(m-1,n,s,p,dp)||find(m,n-1,s,p,dp);
        }
    }
    return dp[m][n]=false;
}
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return find(m-1,n-1,s,p,dp);
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int j=1;j<=n&&p[j-1]=='*';j++) {
            dp[0][j]=true;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*') dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else if(p[j-1]=='?'||s[i-1]==p[j-1]) dp[i][j]=dp[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};
int main(){
    string s1="aa";
    string s2="*";
    Solution obj;
    cout<<obj.isMatch(s1,s2)<<endl;
    return 0;
}