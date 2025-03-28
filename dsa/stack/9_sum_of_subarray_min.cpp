//907
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
class Solution {
public:
void nse1(vector<int>&nums,vector<int>&nse){
    int n=nums.size();
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        if(!st.empty())  nse[i]=st.top();
        st.push(i);
    }

}
void pse1(vector<int>&nums,vector<int>&pse){
      int n=nums.size();
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
        if(!st.empty())  pse[i]=st.top();
        st.push(i);
    }
}
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse(n,n);
        vector<int>pse(n,-1);
        nse1(arr, nse);
        pse1(arr, pse);
        long long  sum=0;
        for(int i=0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            sum=(sum+(1ll*left*right*arr[i])%mod)%mod;

        }
        return sum;
    }
};
int main(){
    Solution s;
    vector<int>arr={3,1,2,4};
    cout<<s.sumSubarrayMins(arr)<<endl;
    return 0;
}