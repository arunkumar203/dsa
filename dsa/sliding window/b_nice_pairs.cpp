//1248
// continuous subarray is called nice if there are k odd numbers on it.
#include <bits/stdc++.h>
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
        int numberOfSubarrays(vector<int>& nums, int k) {
            vector<int>num;
            for(auto i:nums){
                num.push_back(i%2);
            }
           return find(num,k)-find(num,k-1);
        }
    };
    int main(){
        Solution s;
        vector<int>nums={1,1,2,1,1};
        cout<<s.numberOfSubarrays(nums,3)<<endl;
    }