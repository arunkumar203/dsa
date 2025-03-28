#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfshelper(int node, vector<int>& vis, vector<int> l[]) {
        vis[node] = 1;
        for (auto i : l[node]) {
            if (vis[i] == 0) {
                dfshelper(i, vis, l);
            }
        }
    }

    void dfs(int start, vector<int>& vis, vector<int> l[]) {
        dfshelper(start, vis, l);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> l[v];
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    l[i].push_back(j);
                    l[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0) {
                ans++;
                dfs(i, vis, l);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    // here 1 represents a conncetion(edge) btwn 2 nodes.

    int result = solution.findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl;

    return 0;
}
