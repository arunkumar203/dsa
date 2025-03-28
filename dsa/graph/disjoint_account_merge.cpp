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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjoint ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    ds.unionr(i,mp[mail]);
                }
            }
        }
        vector<vector<string>>merge(n);
        for(auto i:mp){
            string mail=i.first;
            int node=ds.findpar(i.second);
            merge[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i=0;i<n;i++) {
            if (merge[i].size()==0) continue;
            sort(merge[i].begin(), merge[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]); 
            temp.insert(temp.end(),merge[i].begin(),merge[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<string>>accounts={{"John","johnsmith@mail.com","john_newyork@mail.com"},
    {"John","johnsmith@mail.com","john00@mail.com"},
    {"Mary","mary@mail.com"},
    {"John","johnnybravo@mail.com"}};
    vector<vector<string>>ans=s.accountsMerge(accounts);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
