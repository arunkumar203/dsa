//583
//min insertions and deletions to convert string a to string b
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int find3(string text1,string text2,vector<vector<int>>&dp3){
        int m=text1.size();
        int n=text2.size();
        string s1=text1;
        string s2=text2;
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
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        int temp=find3(word1,word2,dp);
        return word1.size()+word2.size()-2*temp;
    }
};
int main(){
    string s1="sea";
    string s2="eat";
    Solution s;
    cout<<s.minDistance(s1,s2)<<endl;
    return 0;
}