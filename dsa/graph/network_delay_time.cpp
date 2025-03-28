#include<bits/stdc++.h>
using namespace std;
//given starting node k and n nodes and times of each edge to reach from one node to another
//return the time taken to reach all nodes from k
class Solution {
public:
typedef pair<int,int> pii;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii>l[n+1];
        for(auto i:times){
            l[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto i:l[node]){
                int adnode=i.first;
                int addis=i.second;
                if(addis+dis<dist[adnode]){
                    dist[adnode]=addis+dis;
                    pq.push({addis+dis,adnode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        return ans==1e9?-1:ans;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;
    int result = solution.networkDelayTime(times, n, k);
    cout << "Network delay time: " << result << endl;
    return 0;
}