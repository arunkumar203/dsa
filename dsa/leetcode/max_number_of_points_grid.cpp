//2503
// If queries[i] is strictly greater than the value of the current cell
//  that you are in, then you get one point if it is your first time visiting this cell,
//  and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
// Otherwise, you do not get any points, and you end this process.


//soln
//we process the smallest adj cell first and bigger one next->use min heap(priority queue)
//sort the queries and process the queries in increasing order,
//for each increasing value,points also increase,so we sort,instead of recalculating
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    typedef pair<int,pair<int,int>>pii;
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m=grid.size(),n=grid[0].size();
            vector<int>ans(queries.size(),0);
            vector<pair<int,int>>qu;
            for(int i=0;i<queries.size();i++){
                qu.push_back({queries[i],i});
            }
            sort(qu.begin(),qu.end());
            vector<vector<int>>vis(m,vector<int>(n,0));
            priority_queue<pii,vector<pii>,greater<>>pq;
            pq.push({grid[0][0],{0,0}});
            vis[0][0]=true;
            int cnt=0;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(auto [q,idx]:qu){
                while(!pq.empty() && pq.top().first<q){
                    auto [val,pos]=pq.top();
                    pq.pop();
                    cnt++;
                    int r=pos.first,c=pos.second;
                    for(int i=0;i<4;i++){
                        int nr=r+dr[i];
                        int nc=c+dc[i];
                        if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0){
                            pq.push({grid[nr][nc],{nr,nc}});
                            vis[nr][nc]=1;
                        }
                    }
                }
                ans[idx]=cnt;
            }
            return ans;
    
    
        }
    };
    int main() {
        Solution sol;
        vector<vector<int>> grid = {
            {1, 2, 3},
            {1, 5, 1},
            {3, 1, 1}
        };
        vector<int> queries = {2, 1, 3};
        vector<int> result = sol.maxPoints(grid, queries);
        cout << "Result: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return 0;
    }