#include<bits/stdc++.h>
using namespace std;
//calculate total extraedges,total components and
//to connect k components we need k-1 edges
//if extraedges>=components-1 then return components-1 else return -1
class disjoint{
    public:
    vector<int>rank,parent,size;
    disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
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
            rank[ulpv]++;
        }
    }
    void unions(int u,int v){
        int ulpu=findpar(u);
        int ulpv=findpar(v);
        if(ulpu==ulpv) return;
        if(size[ulpu]<size[ulpv]){
            parent[ulpu]=ulpv;
            size[ulpv]=size[ulpv]+size[ulpu];
        }
        else{
            parent[ulpv]=ulpu;
            size[ulpu]=size[ulpu]+size[ulpv];
        }
    }

};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjoint ds(n);
        int extraedges=0;
        for(auto i:connections){
            if(ds.findpar(i[0])==ds.findpar(i[1])) extraedges++;
            else{
                ds.unionr(i[0],i[1]);
            }
        }
        int compo=0;
        for(int i=0;i<n;i++){
            if(i==ds.parent[i]) compo++;
        }
        return compo-1<=extraedges?compo-1:-1;
        
    }
};
int main(){
    Solution s;
    int n=6;
    vector<vector<int>> connections={{0,1},{0,2},{0,3},{1,2},{1,3}};
    cout<<s.makeConnected(n,connections)<<endl;
    return 0;
}
