// 2091--Removing Minimum and Maximum From Array
#include<bits/stdc++.h>
using namespace std;
int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX,maxi=INT_MIN;
        int temp1=0,temp2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini) {
                mini=nums[i];
                temp1=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                temp2=i;
            }
        }
        int ans1=min(temp1,temp2)+1+nums.size()-max(temp1,temp2);
        int ans2=max(temp1,temp2)+1;
        int ans3=nums.size()-min(temp1,temp2);
        return min({ans1,ans2,ans3});
    }
int main(){
    vector<int>nums={0,-4,19,1,8,-2,-3,5};
    cout<<minimumDeletions(nums)<<endl;
    return 0;
}