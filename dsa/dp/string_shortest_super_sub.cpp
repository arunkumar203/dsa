#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string find1(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp3(m+1,vector<int>(n+1,0));
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
        int i=m-1,j=n-1;
        string ans;
        while (i >= 0 && j >= 0) {
        if (s1[i] == s2[j]) {
            ans.push_back(s1[i]);
            i--;
            j--;
        } else if (dp3[i-1][j] > dp3[i][j-1]) {
            ans.push_back(s1[i]);
            i--;
        } else {
            ans.push_back(s2[j]);
            j--;
        }
        
    }
    while(i>=0){
            ans.push_back(s1[i-1]);
            i--;
        }
         while(j>=0){
            ans.push_back(s2[j-1]);
            j--;
        }
    reverse(ans.begin(), ans.end());
     return ans;   
    }
  string find2(string& s1, string& s2, int i, int j, vector<vector<string>>& dp) {
        // Base cases
        if (i < 0) return s2.substr(0, j + 1);
        if (j < 0) return s1.substr(0, i + 1);
        
        // If already computed
        if (!dp[i][j].empty()) return dp[i][j];
        
        // If characters match
        if (s1[i] == s2[j]) {
            return dp[i][j] = find2(s1, s2, i-1, j-1, dp) + s1[i];
        }
        
        // If characters don't match
        string left = find2(s1, s2, i-1, j, dp) + s1[i];
        string right = find2(s1, s2, i, j-1, dp) + s2[j];
        
        return dp[i][j] = (left.length() <= right.length()) ? left : right;
    }
};
int main(){
    string s1="abac";
    string s2="cab";
    Solution s;
    int m=s1.size();
    int n=s2.size();
     vector<vector<string>>dp(m,vector<string>(n));
    // cout<<s.find1(s1,s2)<<endl;
    cout<<s.find2(s1,s2,m-1,n-1,dp)<<endl;
    return 0;
}