#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int source, int destination) {
    int num_nodes = graph.size();
    vector<int> dis(num_nodes, INT_MAX);
    vector<int> parent(num_nodes, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[source] = 0; 
    pq.push({0, source}); 
    while (!pq.empty()) {
        int u = pq.top().second; 
        pq.pop();
        if (u == destination) {
            break; 
        }
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight_uv = neighbor.second;
            if (dis[u] != INT_MAX && dis[u] + weight_uv < dis[v]) {
                dis[v] = dis[u] + weight_uv;
                parent[v] = u; 
                pq.push({dis[v], v}); 
            }
        }
    }
    vector<int> shortestPath;
    int current = destination;
    while (current != -1) { 
        shortestPath.push_back(current);
        current = parent[current];
    }
    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}
int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {7, 8}},     
        {{0, 4}, {2, 8}, {7, 11}}, 
        {{1, 8}, {3, 7}, {5, 4}, {8, 2}}, 
        {{2, 7}, {4, 9}, {5, 14}}, 
        {{3, 9}, {5, 10}},     
        {{2, 4}, {3, 14}, {4, 10}, {6, 2}}, 
        {{5, 2}, {7, 1}, {8, 6}}, 
        {{0, 8}, {1, 11}, {6, 1}, {8, 7}},
        {{2, 2}, {6, 6}, {7, 7}} 
    };

    int source = 0; 
    int destination = 6; 
     for(int j=0;j<graph.size();j++){
vector<int> shortestPath = dijkstra(graph, source, j);

    cout << "Shortest Path from " << source << " to " << j << ": ";
    for (int node : shortestPath) {
        cout << node << " ";
    }
    cout << endl;
     }
    

    return 0;
}