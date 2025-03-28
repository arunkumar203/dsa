#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
typedef pair<int,int> p;
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        priority_queue<p,vector<p>>maxpq;
        priority_queue<p,vector<p>,greater<p>>minpq;
        int i=0,j=0,ans=0;
        while(j<n){
            maxpq.push({nums[j],j});
            minpq.push({nums[j],j});
            while(maxpq.top().first-minpq.top().first>limit){
                i=min(maxpq.top().second,minpq.top().second)+1;
                //10 1 2 4 7 2 and limit=5
                //after {10,0},{1,1} are pushed max-min=9>5 so we need to pop 1
                while(maxpq.top().second<i){//occurs when j index is less than i
                    maxpq.pop();
                }
                while(minpq.top().second<i){
                    minpq.pop();
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 5, 2, 4, 3};
    int limit = 3;
    int result = solution.longestSubarray(nums, limit);
    cout << "Longest subarray length: " << result << endl;
    return 0;
}