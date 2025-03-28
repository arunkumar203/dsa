//2149
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            vector<int>a,b;
            int n=nums.size();
            for(auto i:nums){
                if(i>0) a.push_back(i);
                else b.push_back(i); 
            }
            int k=0;
            int i=0;
            while(i<n){
                nums[i++]=a[k];
                nums[i++]=b[k++];
            }
            return nums;
            
        }
    };
    int main(){
        Solution s;
        vector<int>nums={-1,1,-2,2,-3,3,-4,4};
        vector<int>res=s.rearrangeArray(nums);
        for(auto i:res){
            cout<<i<<" ";
        }
        cout<<endl;
    }