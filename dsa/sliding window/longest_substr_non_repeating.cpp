//3
// Longest Substring Without Repeating Characters
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int start=-1;
    void print1(string s,int size){
        cout<<s.substr(start,size)<<endl;
    }
        int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        unordered_map<char, int>mp; 
        int ans=0;
        int i=0;
        start=-1;
        for (int j=0; j<s.length();j++) {
            char c=s[j];
            if (mp.count(c)&&mp[c]>=i) {
                //here we move left point only once,so it doesnt require
                //while condition here
                i=mp[c]+1;
            }
            mp[c] = j; 
            if(ans<j-i+1){
                start=i;
                ans=max(ans,j-i+1);
            }
            // ans = max(ans,j-i+1);
        }
        return ans;
        }
    };
    int main(){
        string s="leetcode";
        Solution ss;
        int ans=ss.lengthOfLongestSubstring(s);
        ss.print1(s,ans);
    }