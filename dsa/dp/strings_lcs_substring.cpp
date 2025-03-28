#include<bits/stdc++.h>
using namespace std;
//longest common substring
int find3(string s1,string s2,vector<vector<int>>&dp3){
    int ans=0;
    int m=s1.size();
    int n=s2.size();
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) {
                    dp3[i][j]=1+dp3[i-1][j-1];
                    ans=max(ans,dp3[i][j]);
                }
                else {
                    dp3[i][j]=0;
                }
            }
        }
        return ans;
}
int main(){
    string s1="abcde";
    string s2="ace";
    vector<vector<int>>dp3(s1.size()+1,vector<int>(s2.size()+1,0));
    cout<<find3(s1,s2,dp3)<<endl;
    return 0;
}