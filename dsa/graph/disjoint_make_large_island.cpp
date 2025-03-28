#include<bits/stdc++.h>
using namespace std;
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
bool isvalid(int i,int j,int n){
    return i>=0&&i<n&&j>=0&&j<n;
}
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjoint ds(n*n);
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(isvalid(nr,nc,n)&&grid[nr][nc]==1){
                        int node=i*n+j;
                        int adjnode=nr*n+nc;
                        ds.unions(node,adjnode);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int dr[] = {-1,0,1,0};
                    int dc[] = {0,-1,0,1};
                    set<int>compo;
                    //as 2 adj may be same,so we are storing in set
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(isvalid(nr,nc,n)&&grid[nr][nc]==1){
                            compo.insert(ds.findpar(nr*n+nc));
                        }
                    }
                    int tot=0;
                    for(auto i:compo){
                        tot+=ds.size[i];
                    }
                    ans=max(ans,tot+1);
                }
            }
        }
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[ds.findpar(i)]);
        }
        return ans;


    }
};
int main(){
    vector<vector<int>>grid={{1,0},{0,1}};
    Solution s;
    cout<<s.largestIsland(grid)<<endl;
}