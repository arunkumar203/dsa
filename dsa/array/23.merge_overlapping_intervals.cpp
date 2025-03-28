//56
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            int n=intervals.size();
            sort(intervals.begin(),intervals.end());
            vector<vector<int>>ans;
            for(int i=0;i<n;i++){
                if(ans.empty() ||  intervals[i][0]>ans.back()[1]){
                    ans.push_back(intervals[i]);
                }
                else{
                    ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                }
    
            }
            return ans;
    
        }
    };
    int main() {
        vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
        Solution obj;
        vector<vector<int>> result = obj.merge(intervals);
        for (auto &v : result) {
            for (auto &x : v) cout << x << " ";
            cout << "\n";
        }
        return 0;
    }