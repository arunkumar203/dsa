#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool compare(string s,string t){
    if(s.size()!=t.size()+1) return false;
    int i=0,j=0;
    while(i<s.size()){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }   
    if(i==s.size()&&j==t.size()) return true;
    return false; 
}

    int longestStrChain(vector<string>& words) {
        int n=words.size();
            vector<int>dp(n+1,1);
            sort(words.begin(),words.end(),[](const string&s,const string&t){
            return s.size()<t.size();
            });
    int maxi=0;//stores last ind
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(compare(words[i],words[j])&&dp[i]<1+dp[j]){
                dp[i]=1+dp[j];
                // hash[i]=j;               
            }
        }
        if(dp[maxi]<dp[i]){
                maxi=i;
            }
    }
    return dp[maxi];
    }
};
int main(){
    vector<string>nums={"xbc","pcxbcf","cxbc","pcxbc","xb"};
    Solution s;
    cout<<s.longestStrChain(nums)<<endl;
    return 0;
}