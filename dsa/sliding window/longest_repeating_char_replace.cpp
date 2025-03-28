//424
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int characterReplacement(string s, int k) {
            int ans=0;
            int i=0,j=0;unordered_map<int,int>mp;
            int n=s.length();
            int maxfre=0;
            while(j<n){
                mp[s[j]-'A']++;
                maxfre=max(maxfre,mp[s[j]-'A']);
                //we calculate max freq,so that we could minimze the other changings
                while((j-i+1)-maxfre>k){
                    mp[s[i]-'A']--;
                    i++;
                }
                ans=max(ans,j-i+1);
                j++;
            }
            return ans;
        }
    };
    int main(){
        Solution s;
        string str="AABABBA";
        int k=1;
        cout<<s.characterReplacement(str,k)<<endl;
    }