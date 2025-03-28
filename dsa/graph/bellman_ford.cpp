#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto i:edges){
                // int [u,v,wt]=i;
                int u=i[0];
                int v=i[1];
                int wt=i[2];
                if(dist[u]!=1e8&&dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        for(auto i:edges){
            // int [u,v,w]=i;
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            if(dist[u]!=1e8&&dist[u]+wt<dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};
int main() {
    Solution solution;
    int V = 5; // number of vertices
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 4}, {1, 3, 3}, {2, 1, 6}, {3, 2, 2}, {3, 4, 2}, {4, 0, 3}}; // edges in the graph
    int S = 0; // source vertex
    vector<int> result = solution.bellman_ford(V, edges, S);
    for (int i = 0; i < result.size(); i++) {
        cout << "Distance of vertex " << i << " from the source vertex " << S << ": " << result[i] << endl;
    }
    return 0;
}