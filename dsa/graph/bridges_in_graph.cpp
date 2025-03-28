#include<bits/stdc++.h>
using namespace std;
class Solution {
    int timer=0;
public:
void dfs(int node,int parent,vector<int>&vis,
vector<int>l[],int tin[],int low[],vector<vector<int>>&ans){
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto i:l[node]){
        if(i==parent) continue;
        if(vis[i]==0){
            dfs(i,node,vis,l,tin,low,ans);
            low[node]=min(low[i],low[node]);
            if(low[i]>tin[node]){
                ans.push_back({i,node});
            }
        }
        else{
            low[node]=min(low[node],low[i]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>l[n];
        for(auto i:connections){
            l[i[0]].push_back(i[1]);
            l[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        int tin[n],low[n];
        vector<vector<int>>ans;
        dfs(0,-1,vis,l,tin,low,ans);
        return ans;
    }
};
int main(){
    int n=4;
    vector<vector<int>>connections={{0,1},{1,2},{2,0},{1,3}};
    Solution s;
    vector<vector<int>>ans=s.criticalConnections(n,connections);
    for(auto i:ans){
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    return 0;
}
