//element is a leader if it is greater than all the elements to its right side
#include<bits/stdc++.h>
using namespace std;
void find(vector<int>&nums,int n,vector<int>&ans){
    vector<int>maxi(n,-1);
    maxi[n-1]=nums[n-1];
    //get max element from right
    for(int i=n-2;i>=0;i--){
        maxi[i]=max(maxi[i+1],nums[i]);
    }
    for(int i=0;i<n;i++){
        if(nums[i]==maxi[i]) ans.push_back(nums[i]);
    }
}
int main(){
    vector<int>nums={10,22,12,3,0,6};
    vector<int>ans;
    find(nums,nums.size(),ans);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
}
