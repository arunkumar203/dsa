//2352
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int equalPairs(vector<vector<int>>& grid) {
            int n=grid.size();
            int ans=0;
            map<vector<int>,int>mp;
            for(int i=0;i<n;i++){
                mp[grid[i]]++;
            }
            for(int i=0;i<n;i++){
                vector<int>temp;
                for(int j=0;j<n;j++){
                    temp.push_back(grid[j][i]);
                }
                ans+=mp[temp];
            }
            return ans;
        }
    };
    int main(){
        Solution s;
        // [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
        vector<vector<int>>grid={{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
        cout<<s.equalPairs(grid)<<endl;
    }