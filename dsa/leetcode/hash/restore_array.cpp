//1743
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int>ans;
    void dfs(int u,int v,unordered_map<int,vector<int>>&mp){
        ans.push_back(u);
        for(auto i:mp[u]){
            if(v!=i) dfs(i,u,mp);
        }
    }
        vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
            unordered_map<int,vector<int>>mp;
            for(auto i:adjacentPairs){
                int u=i[0];
                int v=i[1];
                mp[u].push_back(v);
                mp[v].push_back(u);
            }
            int start=-1;
            for(auto i:mp){
                if(i.second.size()==1){
                    start=i.first;
                    break;
                }
            }
            dfs(start,-1,mp);
            return ans;
        }
    };
    int main(){
        Solution s;
        vector<vector<int>>adjacentPairs={{2,1},{3,4},{3,2}};
        //can be either of 1,2 or 2,1 ,so we add edge btwn these 2
        vector<int>ans=s.restoreArray(adjacentPairs);
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }