#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0; 
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, {0, 0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            int dis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if (r == rows - 1 && c == cols - 1) {
                return dis;
            }
            for (int i = 0; i < 4; i++) {              
                int delr = r + dr[i];
                int delc = c + dc[i];
                if (delr >= 0 && delr < rows && delc >= 0 && delc < cols) {
                    int delEffort = max(dis, abs(heights[r][c] - heights[delr][delc]));
                    if (delEffort < dist[delr][delc]) {
                        dist[delr][delc] = delEffort;
                        pq.push({delEffort, {delr, delc}});
                    }
                }
            }
        }
        return -1; 
    }
};
int main() {
    // Test the minimumEffortPath function
    Solution solution;
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };
    int result = solution.minimumEffortPath(heights);
    cout << "Minimum effort path: " << result << endl;

    return 0;
}