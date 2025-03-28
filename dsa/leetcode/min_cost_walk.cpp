//3108
//for given path,cost is bitwise and of all of its path wt
//score will be min if the path moves all way through the graph as & will decrease 
//score if new lower wt is encountered
//score will be same for a component
//if start and end are of same component ,score will be & of all of its compnents wt
//diff components will have diff scores
#include <bits/stdc++.h>
using namespace std;
class disjoint{
    public:
    vector<int>rank,parent,size;
    disjoint(int n){
        rank.resize(n+1,0); 
        parent.resize(n+1); 
        size.resize(n+1,1); 
        for(int i=0;i<=n;i++){ 
            parent[i]=i;
        }
    }
    int findpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findpar(parent[node]);
    }
    void unionr(int u,int v){
        int ulpu=findpar(u);
        int ulpv=findpar(v);
        if(ulpu==ulpv) return;
        if(rank[ulpu]<rank[ulpv]){
            parent[ulpu]=ulpv;
        }
        else if(rank[ulpu]>rank[ulpv]){
            parent[ulpv]=ulpu;
        }
        else{
            parent[ulpv]=ulpu;
            rank[ulpu]++;
        }
    }
};
class Solution {
public:
vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query){
    disjoint dsu(n);
    unordered_map<int,int>scores;
    for(auto i:edges){
        int u=i[0],v=i[1],wt=i[2];
        int pu=dsu.findpar(u);
        int pv=dsu.findpar(v);
        if(!scores.count(pu)) scores[pu]=(1<<21)-1;
        if(!scores.count(pv)) scores[pv]=(1<<21)-1;
        int current_score_u=scores[pu]; 
        int current_score_v=scores[pv]; 
        dsu.unionr(u,v);
        int new_parent = dsu.findpar(u);
        scores[new_parent]=(current_score_u&current_score_v)&wt; 

    }

    vector<int>ans;
    for(auto i:query){
        int u=i[0],v=i[1];
        if(u==v) ans.push_back(0);
        else{
            int pu=dsu.findpar(u);
            int pv=dsu.findpar(v);
            if(pu==pv){
                ans.push_back(scores[pu]);
            }
            else ans.push_back(-1);
        }
    }
    return ans;
 }
 vector<int> minimumCost2(int n, vector<vector<int>>& edges, vector<vector<int>>& query){
    disjoint dsu(n);
    unordered_map<int,int>scores;
    for(auto i:edges){
      int u=i[0],v=i[1];
      dsu.unionr(u,v);
    }
    for(int i=0;i<n;i++){
        int pu=dsu.findpar(i);
        if(!scores.count(pu)) scores[pu]=(1<<21)-1;
    }
    for(auto i:edges){
        int u=i[0],v=i[1],wt=i[2];
        int pu=dsu.findpar(u);
        scores[pu]&=wt;
    }

    vector<int>ans;
    for(auto i:query){
        int u=i[0],v=i[1];
        if(u==v) ans.push_back(0);
        else{
            int pu=dsu.findpar(u);
            int pv=dsu.findpar(v);
            if(pu==pv){
                ans.push_back(scores[pu]);
            }
            else ans.push_back(-1);
        }
    }
    return ans;
 }
void dfs(int node,unordered_map<int,vector<int>>&g,vector<int>&vis,int num,unordered_map<int,int>&mp){
    vis[node]=1;
    mp[node]=num;
    for(auto i:g[node]){
        if(!vis[i]){
            dfs(i,g,vis,num,mp);
        }
    }
}
    vector<int> minimumCost1(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int m=edges.size();
        unordered_map<int,vector<int>>g;
        for(int i=0;i<m;i++){
            int u=edges[i][0],v=edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        unordered_map<int,int>mp;
        int num=1;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,g,vis,num,mp);
                num++;
            }
        }
        vector<int>score(num,pow(2,21)-1);
        for(int i=0;i<m;i++){
            int u=edges[i][0],v=edges[i][1];
            int comp=mp[u];
            score[comp]&=edges[i][2];
        }
        vector<int>ans;
        for(auto i:query){
            if(i[0]==i[1]) ans.push_back(0);
            else if(mp[i[0]]==mp[i[1]]){
                ans.push_back(score[mp[i[0]]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;

    }
};
int main(){
    Solution s;
    int n=5;
    vector<vector<int>>edges={{0,1,7},{1,3,7},{1,2,1}};
    vector<vector<int>>query={{0,3},{3,4}};
    vector<int>ans=s.minimumCost(n,edges,query);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;

}
