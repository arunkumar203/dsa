//75
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int a[3]={0};
            for(auto i:nums){
                a[i]++;
            }
            int i=0;
            while(a[0]--) nums[i++]=0;
            while(a[1]--) nums[i++]=1;
            while(a[2]--) nums[i++]=2;
        }
    };
    int main(){
        Solution s;
        vector<int>nums={2,0,2,1,1,0};
        s.sortColors(nums);
        for(auto i:nums){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    void sortColorsDutch(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
    }