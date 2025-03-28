//Return the city with the smallest number of cities that are reachable through some path and 
//whose distance is at most distanceThreshold, If there are multiple such cities, return 
//the city with the greatest number.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n,vector<int>(n,1e8));
        for(auto i:edges){
            mat[i[0]][i[1]]=i[2];
            mat[i[1]][i[0]]=i[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        int ans=-1;
        int k=n;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(i!=j&&mat[i][j]<=distanceThreshold) temp++;
            }
            if(temp<=k){
                k=temp;
                ans=i;
            }
        }
        return ans;
    }
};

// City 0 -> [City 1, City 2] 
// City 1 -> [City 0, City 2, City 3] 
// City 2 -> [City 0, City 1, City 3] 
// City 3 -> [City 1, City 2] 
// City 0 has 3 cities reachable within distanceThreshold=4 =>ans is 3
int main() {
    Solution solution;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int n = 4;
    int distanceThreshold = 4;
    int result = solution.findTheCity(n, edges, distanceThreshold);
    cout << "City with smallest number of cities: " << result << endl;
    return 0;
}