// return the nearest 0 for each cell and no diagonal

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        
        int n=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>>dis(m,vector<int>(n,0));
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }else{
                    vis[i][j]=0;

                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dis[r][c]=steps;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},steps+1});
                }
            }
        }
        return dis;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> result = sol.updateMatrix(mat);

    cout << "Updated Matrix:\n";
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}