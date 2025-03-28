//85
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
        int maximalRectangle(vector<vector<char>>& matrix) {
            if(matrix.empty())return 0;
            int ans=0;
            int m=matrix.size();
            int n=matrix[0].size();       
            vector<int>heights(n, 0);
            for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                    if(matrix[i][j]=='0') 
                        heights[j]=0;
                    else heights[j]+=1;
                }
                ans=max(ans,largestRectangleArea(heights));
            }
    
            return ans;
    
        }
    };
    
int main(){
    Solution s;
    vector<vector<char>>matrix={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<s.maximalRectangle(matrix)<<endl;
    return 0;
}
