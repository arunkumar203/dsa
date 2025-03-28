#include<bits/stdc++.h>
using namespace std;
vector<int> shortestpath(vector<vector<int>>&edges,int n,int m,int src){
    vector<int> l[n];
    for(auto i:edges){
        l[i[0]].push_back(i[1]);
        l[i[1]].push_back(i[0]);

    }
    vector<int>dis(n,1e9);
    dis[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i:l[node]){
            if(dis[node]+1<dis[i]){
                dis[i]=dis[node]+1;
                q.push(i);
            }
        }
    }
    return dis;
}
int main(){
    int n = 5; 
    int m = 6; 
    int src = 0; 

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}};

    vector<int> result = shortestpath(edges, n, m, src);

    cout << "Shortest distances from source vertex " << src << ":\n";
    for(int i = 0; i < n; i++){
        cout << "Vertex " << i << ": " << result[i] << "\n";
    }

    return 0;
}