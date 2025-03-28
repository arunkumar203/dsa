//2364. Count Bad Pairs
//bad pair if(i<j) and ((i-j) !=nums[i]-nums[j])    
//can be converted to nums[i]-i!=nums[j]-j
//a b c d e (nums[i]-i array)
//if we take d(3rd index),we need to check for a,b,c(3 ele or simply index) with d if all unequal then 3,
//we need to check if we found d before d,use map to track the found elements and their total count 



#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
typedef long long ll;
    long long countBadPairs(vector<int>& nums) {
        unordered_map<ll,ll>mp;
        int n=nums.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-i;
        }
        mp[nums[0]]++;
        for(int i=1;i<n;i++){
            ans+=i-mp[nums[i]];
            mp[nums[i]]++;
        }
        return ans;
    }
};
int main(){
    vector<int>nums={1,2,3,4,5};
    Solution ss;
    cout<<ss.countBadPairs(nums)<<endl;
}
//

//1814 nice pairs
//nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
// class Solution {
// public:
// int mod=1e9+7;
// int rev(int num){
//     int ans=0;
//     while(num){
//         ans=ans*10+num%10;
//         num/=10;
//     }
//     return ans;
// }
//     int countNicePairs(vector<int>& nums) {
//         int n=nums.size();
//         long long ans=0;
//         unordered_map<int,int>mp;
//         for(int i=0;i<n;i++){
//             nums[i]=nums[i]-rev(nums[i]);
//         }
//         mp[nums[0]]++;
//         for(int i=1;i<n;i++){
//             ans=(ans+mp[nums[i]])%mod;
//             mp[nums[i]]++;
//         }
//         return int(ans%mod);
//     }
// };