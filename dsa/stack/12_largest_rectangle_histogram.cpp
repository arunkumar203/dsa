//84
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int largestRectangleArea(vector<int>& nums){
        stack<int>st;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                int ele=st.top(); st.pop();
                int nse=i;
                int  pse=st.empty()?-1:st.top();
                ans=max(ans,(nse-pse-1)*nums[ele]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int ele=st.top(); st.pop();
            int pse=st.empty()?-1:st.top();
            ans=max(ans,(nse-pse-1)*nums[ele]);
        }
        return ans;
    }
    void nextsmallerElement(vector<int>& nums,vector<int>&nse) {
        int n = nums.size();
        // vector<int> nse(n, -1);
        stack<int> st;
    
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }
    
    }
    
    void previousSmallerElement(vector<int>& nums,vector<int>&pse) {
        int n = nums.size();
        // vector<int> pse(n, -1);
        stack<int> st;
    
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        // return pse;
    }
    
        int largestRectangleArea1(vector<int>& heights) {
            int n=heights.size();
            vector<int>nse(n,n);
            vector<int>pse(n,-1);
            previousSmallerElement(heights,pse);
            nextsmallerElement(heights,nse);
            int ans=0;
            for(int i=0;i<n;i++){
                ans=max(ans,heights[i]*(nse[i]-pse[i]-1));
            }
            return ans;
    
        }
    };
    
int main(){
    Solution s;
    vector<int>nums={2,1,5,6,2,3};
    cout<<s.largestRectangleArea(nums)<<endl;
    cout<<s.largestRectangleArea1(nums)<<endl;
    return 0;
}
