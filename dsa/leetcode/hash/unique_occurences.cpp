//1207 
//Given an array of integers arr, return true if the number of occurrences of each value
// in the array is unique or false otherw
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool uniqueOccurrences(vector<int>& arr) {
            unordered_map<int,int>mp;
            for(auto i:arr){
                mp[i]++;
            }
            unordered_set<int>st;
            for(auto i:mp){
                int freq=i.second;
                if(st.find(freq)==st.end()) st.insert(freq);
                else return false;
            }
            return true;
        }
    };

    int main(){
        Solution s;
        vector<int>nums={1,2,2,1,1,3};
        cout<<s.uniqueOccurrences(nums)<<endl;
    }