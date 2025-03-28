//532
//|nums[i] - nums[j]| == k
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        if(k==0){
            int ans=0;
            for(auto i:mp){
                auto [n,freq]=i;
                if(freq>1) ans++;
            }
            return ans;
        }
        else{
            int ans=0;
            for(auto i:mp){
                auto [n,freq]=i;
                if(mp.count(n-k)) ans++;
            }
            return ans;
        }
        return 1;
    }
};
int main(){
    vector<int>nums={1,2,3,4,5};
    Solution ss;
    cout<<ss.findPairs(nums,1)<<endl;
}