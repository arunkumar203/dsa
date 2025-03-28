//replace all 0s with x which are surrounded by x
//take all 0s on borders(all edges) and make it as vis as 1 and all its connected in 4 directions 
// as vis as 1
//next replace all os which are unvisited(basically which are inside) as x


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& vis, vector<vector<char>>& board) {
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int m = board.size();
        int n = board[0].size();
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && board[nr][nc] == 'O') {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    vis[i][j] = 1;
                }
            }
        }


        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                vis[i][0] = 1;
                q.push({i, 0});
                bfs(q, vis, board);
            }
            if (board[i][n - 1] == 'O') {
                vis[i][n - 1] = 1;
                q.push({i, n - 1});
                bfs(q, vis, board);
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                vis[0][j] = 1;
                q.push({0, j});
                bfs(q, vis, board);
            }
            if (board[m - 1][j] == 'O') {
                vis[m - 1][j] = 1;
                q.push({m - 1, j});
                bfs(q, vis, board);
            }
        }


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Original board:" << endl;
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    solution.solve(board);

    cout << "Board after running solve:" << endl;
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
