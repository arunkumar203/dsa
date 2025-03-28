///2225
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> findWinners(vector<vector<int>>& matches) {
            set<int>win;
            unordered_map<int,int>mp;
            for(auto i:matches){
                int winn=i[0];
                int loss=i[1];
                win.insert(winn);
                mp[loss]++;
            }
           vector<vector<int>>ans;
           vector<int>temp1;
           vector<int>temp2;
           for(auto i:win){
            if(!mp.count(i)) temp1.push_back(i);
           }
           for(auto [i,j]:mp){
            if(j==1) temp2.push_back(i);
           }
           sort(temp2.begin(),temp2.end());
           ans.push_back(temp1);
           ans.push_back(temp2);
           return ans;
        }
    };
    // [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
    int main(){
        Solution s;
        vector<vector<int>>matches={{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
        vector<vector<int>>ans=s.findWinners(matches);
        //only winners(never lost)
        //lost only once
        for(auto i:ans){
            for(auto j:i) cout<<j<<" ";
            cout<<endl;
        }
        return 0;
    }