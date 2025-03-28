#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
typedef pair<int, pair<int, int>> pp;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>l[n];
        vector<int>dist(n,1e9);
        for(int i=0;i<flights.size();i++){
            l[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int>vis(n,0);
        vis[src]=1;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0,{src,0}});
        dist[src]=0;
        while(!pq.empty()){
            int stops=pq.top().first;
            int node=pq.top().second.first;
            int cost=pq.top().second.second;
            vis[node]=1;
            pq.pop();
            if(stops>k) continue;
            for(auto i:l[node]){
                int adnode=i.first;
                int wt=i.second;
                if(!vis[adnode]&&cost+wt<dist[adnode]&&stops<=k){
                    dist[adnode]=cost+wt;
                    pq.push({stops+1,{adnode,dist[adnode]}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];


    }
};
int main() {
    Solution solution;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};
    clock_t start = clock();
    int result = solution.findCheapestPrice(4, flights, 0, 3, 10);
    clock_t end = clock();
    
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    
    cout << "Cheapest price: " << result << endl;
    cout << "Time taken: " << fixed << time_taken << setprecision(5) << " seconds" << endl;

    return 0;
}