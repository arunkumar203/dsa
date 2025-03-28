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
private:
    bool isValid(int adjr, int adjc, int n, int m) {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    }
public:
    vector<int> numOfIslands(int m, int n,
                             vector<vector<int>> &operators) {
        disjoint ds(m*n);
        int vis[m][n];
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;
        for (auto it : operators) {
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            // row - 1, col
            // row , col + 1
            // row + 1, col
            // row, col - 1;
            int dr[] = { -1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int ind = 0; ind < 4; ind++) {
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];
                if (isValid(adjr, adjc, m, n)) {
                    if (vis[adjr][adjc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = adjr * n + adjc;
                        if (ds.findpar(nodeNo) != ds.findpar(adjNodeNo)) {
                            cnt--;
                            ds.unions(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};



int main() {

    int m = 4, n = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };


    Solution obj;
    vector<int> ans = obj.numOfIslands(m, n, operators);
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}