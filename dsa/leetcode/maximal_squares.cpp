//221
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();
            vector<vector<int>>dp(m+1,vector<int>(n+1,0));
            int ans=0;
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(matrix[i-1][j-1]=='1'){
                        dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                        ans=max(ans,dp[i][j]);
                    }
                }
            }
            return ans*ans;
        }
    };
    int main(){
        Solution s;
        vector<vector<char>>matrix={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        cout<<s.maximalSquare(matrix)<<endl;
        return 0;
    }