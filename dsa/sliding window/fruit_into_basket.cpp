//904
//take contnuois of max of 2 types
#include<bits/stdc++.h>
using namespace std;
// class Solution {
//     public:
//     bool find(unordered_map<int,int>&mp){
//         int temp=0;
//         for(auto i:mp){
//             if(i.second>0) temp++;
//         }
//         return temp<=2;
//     }
    
//         int totalFruit(vector<int>& fruits) {
//             unordered_map<int,int>mp;
//             int ans=0,i=0,j=0;
//             int n=fruits.size();
//             while(j<n){
//                 mp[fruits[j]]++;
//                 while(!find(mp)){
//                     //deleting the left 
//                     mp[fruits[i]]--;
//                     i++;
                    
//                 }
//                 ans=max(ans,j-i+1);
//                 j++;
//             }
//             return ans;
//         }
//     };
//     int main(){
//         Solution s;
//         vector<int>fruits={1,2,3,2,2};
//         cout<<s.totalFruit(fruits)<<endl;
//     }

//tweaked version of above is longest substr with atmost k distinct characters

// int longestSubstrAtMostKDistinct1(const string &s, int k) {
//     unordered_map<char,int> freq;
//     int left = 0, maxLen = 0, distinctCount = 0;
//     for(int right = 0; right < (int)s.size(); right++){
//         if(freq[s[right]] == 0) distinctCount++;
//         freq[s[right]]++;
//         while(distinctCount > k){
//             freq[s[left]]--;
//             if(freq[s[left]] == 0) distinctCount--;
//             left++;
//         }
//         maxLen = max(maxLen, right - left + 1);
//     }
//     return maxLen;
// }
int longestSubstrAtMostKDistinct(const string &s, int k) {
    unordered_map<char,int> freq;
    int left = 0, maxLen = 0;
    for(int right = 0; right < (int)s.size(); right++){
        if(freq[s[right]] == 0) k--;
        freq[s[right]]++;
        while(k<0){
            freq[s[left]]--;
            if(freq[s[left]] == 0) k++;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int main(){
    string s="eceba";
    int k=2;
    cout<<longestSubstrAtMostKDistinct(s,k)<<endl;
}

