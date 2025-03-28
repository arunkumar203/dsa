//2392
//The number abovei should appear in a row that is strictly above the row at which the number
// belowi appears for all i from 0 to n - 1.
//The number lefti should appear in a column that is strictly left of the column at which 
//the number righti appears for all i from 0 to m - 1.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool dfs(int node,vector<int>&vis, stack<int> &st,vector<int> l[]) {
		vis[node] = 1;
		for (auto it : l[node]) {
			if (!vis[it]) {
                if(dfs(it, vis, st, l)) return true;//cycle
            }
            else if(vis[it]==1){
                return true;
            } 
		}
        vis[node]=2;
		st.push(node);
        return false;
	}
    vector<int> topo(vector<vector<int>>adj,int k)
	{
        vector<int>l[k+1];
        for(auto i:adj){
            l[i[0]].push_back(i[1]);
        }
        vector<int>vis(k+1,0);
		stack<int> st;
		for (int i = 1; i<=k; i++) {
			if (!vis[i]) {
				if(dfs(i, vis, st, l)) return {};
			}
		}
		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions){
        vector<int>row=topo(rowConditions,k);
        vector<int>col=topo(colConditions,k);
        if(row.empty()||col.empty()) return {};
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=0;i<row.size();i++){
            for(int j=0;j<col.size();j++){
                if(row[i]==col[j]){
                    ans[i][j]=row[i];
                }
            }
        }
        return ans;

    }
};
//Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
int main(){
    int k=3;
    vector<vector<int>>row={{1,2},{3,2}};
    vector<vector<int>>col={{2,1},{3,2}};
    Solution s;
    vector<vector<int>>ans=s.buildMatrix(k,row,col);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}