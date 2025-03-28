#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void print2(vector<vector<int>>&dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int find(int m,int n,string s1,string s2,vector<vector<int>>&dp){
    if(m<0||n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if(s1[m]==s2[n]) return dp[m][n]=1+find(m-1,n-1,s1,s2,dp);
    return dp[m][n]=max(find(m-1,n,s1,s2,dp),find(m,n-1,s1,s2,dp));
}
int find2(string text1,string text2,vector<vector<int>>&dp2){
        int m=text1.size();
        int n=text2.size();
        string s1=text1;
        string s2=text2;     
        for(int i=0;i<m;i++){
            if(s1[i]==s2[0]) dp2[i][0]=1;
            else dp2[i][0]=(i > 0)?dp2[i-1][0]:0;//to retain the value of previous cell
        }
        for(int i=0;i<n;i++){
            if(s1[0]==s2[i]) dp2[0][i]=1;
            else dp2[0][i]=(i>0)?dp2[0][i-1]:0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(s1[i]==s2[j]) {
                    dp2[i][j]=1+dp2[i-1][j-1];
                }
                else {
                    dp2[i][j]=max(dp2[i][j-1],dp2[i-1][j]);
                }
            }
        }
        return dp2[m-1][n-1];
}
int find3(string text1,string text2,vector<vector<int>>&dp3){
        int m=text1.size();
        int n=text2.size();
        string s1=text1;
        string s2=text2;
        // for(int i=0;i<=m;i++) dp3[i][0]=0;
        // for(int j=0;j<=n;j++) dp3[0][j]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                //dp(i,j)is till 0to i-1 and 0 to j-1 of s1,s2 respectively
                if(s1[i-1]==s2[j-1]) {
                    dp3[i][j]=1+dp3[i-1][j-1];
                }
                else {
                    dp3[i][j]=max(dp3[i][j-1],dp3[i-1][j]);
                }
            }
        }
        return dp3[m][n];
}
int find4(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
            } else {
                curr[j] = max(curr[j - 1], prev[j]);
            }
        }
        prev = curr;
    }
    return curr[n];
}

  
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp1(text1.size(),vector<int>(text2.size(),-1));
        int temp1=find(text1.size()-1,text2.size()-1,text1,text2,dp1);
        print2(dp1);
        vector<vector<int>>dp2(text1.size(),vector<int>(text2.size(),0));
        vector<vector<int>>dp3(text1.size(),vector<int>(text2.size(),0));
        int temp2=find2(text1,text2,dp2);
        int temp3=find2(text1,text2,dp3);
        print2(dp2);
        print2(dp3);
        return temp1;
        
    }
};
int main() {
    string s1="abcde";
    string s2="ace";
    Solution s;
    cout<<s.longestCommonSubsequence(s1,s2)<<endl;
    return 0;
}