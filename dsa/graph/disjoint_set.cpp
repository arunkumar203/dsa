#include<bits/stdc++.h>
// #include<iostream>
using namespace std;
void take(){
     freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
}
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
            rank[ulpu]++;
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
int main(){
//    take();
   disjoint ds=disjoint(7);
   ds.unionr(1,2);
   ds.unionr(2,3);
   ds.unionr(4,5);
   ds.unionr(6,7);
   ds.unionr(5,6);
   if(ds.findpar(3)==ds.findpar(7)) cout<<"same"<<endl;
   else cout<<"not same"<<endl;
   ds.unionr(3,7);
   if(ds.findpar(3)==ds.findpar(7)) cout<<"same"<<endl;
   else cout<<"not same"<<endl;


   



    return 0;
}

