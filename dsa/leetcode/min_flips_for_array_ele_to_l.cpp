//2997-Minimum Number of Operations to Make Array XOR Equal to K
#include<bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums, int k) {
        int temp=0,ans=0;
        for(auto i:nums) temp^=i;
        while(temp>0||k>0){
            if((temp&1)!=(k&1)) ans++;
            temp=temp>>1;
            k=k>>1;
        }
        return ans;
    }
int main(){
    vector<int>nums={1,2,3,4};
    int k=1;
    cout<<minOperations(nums,k)<<endl;
    return 0;
}