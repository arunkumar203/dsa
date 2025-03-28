#include<bits/stdc++.h>
using namespace std;

void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& arr, int n, int m) {
    vis[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int dei = -1; dei <= 1; dei++) {
            for (int dec = -1; dec <= 1; dec++) {
                int curr = row + dei;
                int curc = col + dec;
                if (curr >= 0 && curc >= 0 && curr < n && curc < m && arr[curr][curc] == 1 && !vis[curr][curc]) {
                    vis[curr][curc] = 1;
                    q.push({curr, curc});
                }
            }
        }
    }
}

int getTotalIslands(vector<vector<int>>& arr, int n, int m) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && !vis[i][j]) {
                ans++;
                bfs(i, j, vis, arr, n, m);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1}
    };

    cout << getTotalIslands(arr, 4, 5)<<endl;
    return 0;
}
