#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int find3(string s1,string s2,vector<vector<int>>&dp3,int m){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                //dp(i,j)is till 0to i-1 and 0 to j-1 of s1,s2 respectively
                if(s1[i-1]==s2[j-1]) {
                    dp3[i][j]=1+dp3[i-1][j-1];
                }
                else {
                    dp3[i][j]=max(dp3[i][j-1],dp3[i-1][j]);
                }
            }
        }
        return dp3[m][m];
}
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
        string s1=s;
        reverse(s.begin(),s.end());
        return find3(s,s1,dp,s.size());
    }
};
int main(){
    string s="bbbab";
    Solution s1;
    cout<<s1.longestPalindromeSubseq(s)<<endl;
    return 0;
}