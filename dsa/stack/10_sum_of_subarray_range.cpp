//2104
#include <bits/stdc++.h>
using namespace std;
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
        long long sumSubarrayMins(vector<int>& arr) {
            int n=arr.size();
            vector<int>nse(n,n);
            vector<int>pse(n,-1);
            nse1(arr, nse);
            pse1(arr, pse);
            long long  sum=0;
            for(int i=0;i<n;i++){
                int left = i - pse[i];
                int right = nse[i] - i;
                sum+=(1ll*left*right*arr[i]);
    
            }
            return sum;
        }
    
    void nge1(vector<int>&nums,vector<int>&nge){
        int n=nums.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(!st.empty())  nge[i]=st.top();
            st.push(i);
        }
    
    }
    void pge1(vector<int>&nums,vector<int>&pge){
          int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(!st.empty())  pge[i]=st.top();
            st.push(i);
        }
    }
       long long sumSubarrayMaxs(vector<int>& arr) {
            int n=arr.size();
             vector<int>nge(n,n);
            vector<int>pge(n,-1);
            nge1(arr, nge);
            pge1(arr, pge);
    
            long long  sum=0;
            for(int i=0;i<n;i++){
                int left = i - pge[i];
                int right = nge[i] - i;
                sum+=(1ll*left*right*arr[i]);
    
            }
            return sum;
        }
    
        long long subArrayRanges(vector<int>& nums) {
            return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
        }
    };
    
int main(){
    Solution s;
    vector<int>arr={1,2,3};
    cout<<s.subArrayRanges(arr)<<endl;
    return 0;
}
