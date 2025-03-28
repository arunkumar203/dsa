#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int timer = 0;
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<int>& mark, vector<int> adj[]) {
        vis[node] = 1;   
        tin[node] = low[node] = timer++;
        int child = 0;
        for (auto i : adj[node]) {
            if (i == parent) continue;
            if (!vis[i]) {
                dfs(i, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[i]);
                if (low[i] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[i]);
            }
        }
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }

    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        if (ans.empty()) ans.push_back(-1);
        return ans;
    }
};
int main() {
    int n = 5; // number of nodes
    vector<int> adj[n];
    // add edges to the adjacency list
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(4);
    adj[4].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(3);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(2);
    adj[3].push_back(4);

    

    Solution obj;
    vector<int> result = obj.articulationPoints(n, adj);

    cout << "Articulation Points: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}