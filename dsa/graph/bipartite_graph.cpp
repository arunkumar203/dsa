//using dfs
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int node, int colo, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = colo;
        for (auto i : graph[node]) {
            if (color[i] == -1) {
                if (dfs(i, !colo, color, graph) == false) return false;
            } else if (color[i] == color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> graph1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << "Graph 1 is bipartite: " << (sol.isBipartite(graph1) ? "true" : "false") << endl;

    vector<vector<int>> graph2 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << "Graph 2 is bipartite: " << (sol.isBipartite(graph2) ? "true" : "false") << endl;

    return 0;
}



//using bfs
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); 
        queue<int> q; 

        for (int start = 0; start < n; ++start) { 
            if (color[start] == -1) {
                color[start] = 0;
                q.push(start);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) { 
                            color[neighbor] = !color[node]; 
                            q.push(neighbor); 
                        } else if (color[neighbor] == color[node]) {
                            return false; 
                        }
                    }
                }
            }
        }
        return true; 
    }
};

int main() {
    Solution sol;

    vector<vector<int>> graph1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << "Graph 1 is bipartite: " << (sol.isBipartite(graph1) ? "true" : "false") << endl;

    vector<vector<int>> graph2 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << "Graph 2 is bipartite: " << (sol.isBipartite(graph2) ? "true" : "false") << endl;

    return 0;
}