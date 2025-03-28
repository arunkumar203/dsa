//i,prev
//i is from 0 to n-1 ans prev is from -1 to n-1 so we shift prev by 1
#include<bits/stdc++.h>
using namespace std;
vector<int> find3(vector<int>&nums,int n){
    vector<int>dp(n+1,1);
    vector<int>hash(n);
    for(int i=0;i<n;i++){
        hash[i]=i;
    }
    int maxi=0;//stores last ind
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]&&dp[i]<1+dp[j]){
                dp[i]=1+dp[j];
                hash[i]=j;               
            }
        }
        if(dp[maxi]<dp[i]){
                maxi=i;
            }
    }
    // int temp=*max_element(dp.begin(),dp.end());
    vector<int>ans;
    ans.push_back(nums[maxi]);
    while(maxi!=hash[maxi]){
        maxi=hash[maxi];
        ans.push_back(nums[maxi]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    // vector<int>nums={10,9,2,5,3,7,101,18};
    vector<int>nums={2,2,2,2,2};
    vector<int>ans=find3(nums,nums.size());
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}