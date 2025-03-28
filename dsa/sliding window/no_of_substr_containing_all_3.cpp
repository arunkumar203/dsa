//1358
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool find(vector<int>&mp){
        int temp=0;
        for(auto i:mp){
            if(i>=1) temp++;
        }
        return temp==3;
    }
        int numberOfSubstrings(string s) {
            int ans=0;
            int i=0,j=0;
            int n=s.length();
            vector<int>mp(3,0);
            while(j<n){
                mp[s[j]-'a']++;
                while(find(mp)){
                    ans+=n-j;
                    //ans is updated here as it forms the valid case
                    //and not as the usual negative case in while loop
                    //if we get abc,in curr window,it is valid ans even if we move further
                    //it will be valid
                    //abc,abca,abcab,abcabc(6-2=4)
                    mp[s[i]-'a']--;
                    i++;
                }
                j++;
    
            }
            return ans;
        }
    };
    int main(){
        Solution s;
        string str="abcabc";
        cout<<s.numberOfSubstrings(str)<<endl;
    }