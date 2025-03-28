// ancestor of a node is from which we can reach to give node
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(int node,vector<int>l[],vector<int>&vis){
    vis[node]=1;
    for(auto i:l[node]){
        if(!vis[i]){
            dfs(i,l,vis);
        }
    }
}
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        vector<int>l[n];
        for(auto i:edges){
            l[i[1]].push_back(i[0]);
            //v->u   reversing the graph;
            //what and all nodes we are able to reach are its ancestors
        }
        for(int i=0;i<n;i++){
            vector<int>temp;
            vector<int>vis(n,0);
            dfs(i,l,vis);
            for(int j=0;j<n;j++){
                if(j==i) continue;
                if(vis[j]){
                    temp.push_back(j);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> edges = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};
    vector<vector<int>> result = solution.getAncestors(8, edges);
    int temp=-1;
    for(auto i:result){
        temp++;
        cout<<temp<<":";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}