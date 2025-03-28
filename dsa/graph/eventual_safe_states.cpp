#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>&vis,vector<int>&check) {
        vis[node] = 1;
        check[node] = 0; 
        for (auto i : graph[node]) {
            if (!vis[i]) {
                if (dfs(i, graph, vis, check)) {
                    return true; 
                }
            } else if (check[i] == 0) { 
                return true; 
            }
        }
        check[node] = 1; 
        return false; 
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>check(n,0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, check);
            }
        }
        for (int i = 0; i < n; i++) {
            if (check[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    // Example usage:
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    Solution sol;
    vector<int> safeNodes = sol.eventualSafeNodes(graph);
    cout << "Eventual Safe Nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}