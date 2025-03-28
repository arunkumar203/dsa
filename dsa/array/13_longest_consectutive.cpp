//128
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            // return find(nums)
            int n=nums.size();
            int ans=0;       
            unordered_set<int>st;
            for(auto i:nums){
                st.insert(i);
            }
            for(auto i:st){
                int parent=i-1;
                if(st.find(parent)==st.end()){
                    int next=i+1;
                    int temp=1;
                    while(st.find(next)!=st.end()){
                        next++;
                        temp++;
                    }
                    if(temp>ans) ans=temp;
    
                }
            }
            return ans;
    
    
    
        }
    };
    int main(){
        Solution s;
        vector<int>nums={100,4,200,1,3,2};
        cout<<s.longestConsecutive(nums)<<endl;
    }