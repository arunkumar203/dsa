#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int>topoSort(int n,vector<int>adj[]){
        int indegree[n]={0};
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            topo.push_back(temp);
            for(auto i:adj[temp]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        return topo;
    }
};
int main() {
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}