#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<long long, long long> pii;
    long long countPaths(int n, vector<vector<int>> &roads) {
        vector<pii> l[n];
        for (auto it : roads) {
            l[it[0]].push_back({it[1], it[2]});
            l[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<long long> dist(n, LLONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        long long mod = 1e9 + 7;
        while (!pq.empty()) {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for (auto it : l[node]) {
                long long lNode = it.first;
                long long edW = it.second;
                if (dis + edW < dist[lNode]) {
                    dist[lNode] = dis + edW;
                    pq.push({dis + edW, lNode});
                    ways[lNode] = ways[node];
                } else if (dis + edW == dist[lNode]) {
                    ways[lNode] = (ways[lNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
int main() {
    int n = 5; // number of nodes in the graph
    vector<vector<int>> roads = {{0, 1, 2}, {0, 2, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 2}, {2, 4, 1}, {3, 4, 3}}; // edges in the graph

    Solution obj;
    long long result = obj.countPaths(n, roads);
    cout << "Number of ways to reach from node 0 to node " << n-1 << ": " << result << endl;

    return 0;
}