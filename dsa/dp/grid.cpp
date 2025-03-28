#include<bits/stdc++.h>
using namespace std;
int find(int m,int n){
    if(m==1 && n==1) return 1;
    if(m<0 || n<0) return 0;  //making sure to return if the specific goes beyound the grid
    return find(m-1,n)+find(m,n-1);
    
}

int main(){
    // int m,n;
    // cout<<"enter m,n:";
    // cin>>m>>n;
    int n;
    cin>>n;
    int m=n;
    cout<<find(m,n)<<endl;

    
    
}

//tabulation


int find(int m, int n, vector<vector<int>>& dp) {
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int i = 0; i < n; i++)  dp[0][i] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return find(m, n, dp);
    }