//137
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int singleNumber1(vector<int>& nums) {
            int ans=0;
            for(int i=0;i<32;i++){
                int temp=(1<<i);
                int ones=0;
                for(auto i:nums){
                    // if((i&temp)>0) ones++;   doesnt work
                    //  if(i&temp) ones++;   works
                     if((i&temp)!=0) ones++;
                }
                if((ones%3)!=0)
                ans|=temp;
            }
            return ans;
        }
        int singleNumber(std::vector<int>& nums) {
            int ones = 0, twos = 0;
            for (int x : nums) {
                ones = (ones ^ x) & ~twos;
                twos = (twos ^ x) & ~ones;
            }
            return ones;
        }
        int singleNumber2(vector<int>& nums) {
            unordered_map<int,int>mp;
            int ans=0;
            for(auto i:nums){
                mp[i]++;
            }
            for(auto i:nums){
                if(mp[i]==1){
                    ans=i;
                    break;
                }
            }
            return ans;
        }
    };
    
int main(){
    Solution s;
    vector<int> nums = {2,2,3,2};
    cout<<s.singleNumber(nums)<<endl;
    cout<<s.singleNumber1(nums)<<endl;
    return 0;
}

