#include <bits/stdc++.h>
using namespace std;
vector<int> l[10];
void addEdge(int a,int b){
    l[a].push_back(b);
    l[b].push_back(a);
}
void bfs(int start){
    int  vis[10]={0};
    vis[start]=1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto i:l[curr]){
            if(vis[i]==0){
                vis[i]=1;
                q.push(i);
            }
        }
    }
    cout<<endl;
}
void dfshelper(int vertex,int vis[]){
    vis[vertex]=1;
    cout<<vertex<<" ";
    for(auto i:l[vertex]){
        if(vis[i]==0){
            dfshelper(i,vis);
        }
    }
}
void dfs(int start){
    int vis[10]={0};
    dfshelper(start,vis);
    cout<<endl;
}
int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);
    addEdge(4, 7);
    bfs(0);
    dfs(0);

    return 0;
}
