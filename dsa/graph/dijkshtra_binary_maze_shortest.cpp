#include<bits/stdc++.h>
using namespace std;
//move only throygh 0s and avoid 1s and movable in 8 dir
class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1; 
        }
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1; 
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({1, {0, 0}}); //we need to return length so  initial element is of length 1
        vis[0][0] = 1;
        while (!pq.empty()) {
            int dis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            vis[r][c]=1;
            pq.pop();
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int delr = r + i;
                    int delc = c + j;
                    if (delr >= 0 && delr < n && delc >= 0 && delc < n && 
                        grid[delr][delc] == 0 && !vis[delr][delc]&& dis + 1 < dist[delr][delc]) {
                        dist[delr][delc] = dis + 1;
                        pq.push({dis + 1, {delr, delc}});
                    }
                }
            }
        }
        return dist[n - 1][n - 1] == 1e9 ? -1 : dist[n - 1][n - 1]; 
    }
};
int main(){
    vector<vector<int>> grid = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };
    Solution obj;
    cout << obj.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}