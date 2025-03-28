#include<bits/stdc++.h>
using namespace std;
class solution{
    private:
    void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&st){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        st.push(node);
    }
    void dfs1(int node,vector<int>&vis,vector<int>adjr[]){
        vis[node]=1;
        cout<<node<<" ";
        for(auto i:adjr[node]){
            if(!vis[i]){
                dfs1(i,vis,adjr);
            }
        }
    }
    public:
    int kosaraju(int V,vector<int>adj[]){
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        vector<int>adjr[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto j:adj[i]){
                adjr[j].push_back(i);
            }
        }
        int ans=0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                ans++;
                dfs1(node, vis, adjr);
                cout<<endl;
            }
        }
        return ans;
    }
};
int main() {

    int n = 8;
    int edges[10][2] = {{0, 1}, {1, 2}, {2, 0},
    {2, 3},{3, 4},{4, 5},
    {5, 6},{6, 4},{6, 7},
    {4, 7}};
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    solution obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}



