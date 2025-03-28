//3014 chars are not repetitive
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minimumPushes1(string word) {
            unordered_map<int,int>mp;
            int currkey=2;
            int ans=0;
            for(auto i:word){
                if(currkey>9) currkey=2;
                mp[currkey]++;
                ans+=mp[currkey];
                currkey++;
            }
            return ans;
        }
        //3016 chars are repetitive
        int minimumPushes(string word){
             vector<int>mp(26,0);
            for(auto i:word){
                mp[i-'a']++;
            }
            int ans=0;
            sort(mp.begin(),mp.end(),greater<int>());
            for(int i=0;i<26;i++){
                int freq=mp[i];
                int press=i/8 + 1;
                //only 8 digits 2-9
                ans+=freq*press;
            }
            return ans;
        }
    };
    int main(){
        Solution s;
        string word="aabbccddeeffgghhiiiiii";
        cout<<s.minimumPushes(word)<<endl;
    }