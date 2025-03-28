#include<bits/stdc++.h>
using namespace std;
void find(int ind,vector<int>&candidates,vector<int>&ds,vector<vector<int>>&ans,int target){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<candidates.size();i++){
        if(i>ind && candidates[i]==candidates[i-1]) continue;
        if(target>=0) {
            ds.push_back(candidates[i]);
            find(i+1,candidates,ds,ans,target-candidates[i]);
            ds.pop_back();
        }
    }
}
int main(){
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target=8;
    find(0,candidates,ds,ans,target);
    for(auto it:ans){
        for(auto num:it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
   
}