//930
//consists of 0,1 return total subarryas with sum=k;
//max sum of k  -   max sum of k-1
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int find(vector<int>&nums,int k){
        if(k<0) return 0;
        int i=0,j=0,sum=0,temp=0;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>k){
                sum-=nums[i];
                i++;
            }
            temp+=j-i+1;
            j++;
        }
        return temp;
       }
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return find(nums,goal)-find(nums,goal-1);
        }
    };
    int main(){
        Solution s;
        vector<int>nums={1,0,1,0,1};
        int k=2;
        cout<<s.numSubarraysWithSum(nums,k)<<endl;
    }

    //another tweaked  version is longest substr with  k distinct int
// class Solution {
//     public:
//     // unordered_map<int,int>mp;
//     int find(vector<int>&nums,int k){
//         unordered_map<int,int>mp;
//         int n=nums.size(),i=0,j=0,ans=0;
//         while(j<n){
//             // if(mp.count(nums[j])==0) k--;
//             if(mp[nums[j]]==0) k--;
//             mp[nums[j]]++;;
//             while(k<0){
//                 mp[nums[i]]--;
//                 if(mp[nums[i]]==0) k++;
//                 i++;
//             }
//             ans+=j-i+1;
//             j++;
    
//         }
//         return ans;
//     }
    
//         int subarraysWithKDistinct(vector<int>& nums, int k) {

//             return find(nums,k)-find(nums,k-1);
    
//         }
            
        
//     };
//     int main(){
//         Solution s;
//         vector<int>nums={1,2,1,2,3};
//         int k=2;
//         cout<<s.subarraysWithKDistinct(nums,k)<<endl;
//     }