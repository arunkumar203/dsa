//given rod of len N,and price of each length of rod,find max profit
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int find(int n,int N,int price[],vector<vector<int>>&dp){
    //   if(n==0) return N*price[n];
    if(n<0) return 0;
      if(dp[n][N]!=-1) return dp[n][N];
      int nottake=find(n-1,N,price,dp);
      int take=INT_MIN;
      int currrodlen=n+1;
      if(currrodlen<=N) take=price[n]+find(n,N-currrodlen,price,dp);
      return dp[n][N]=max(take,nottake);
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return find(n-1,n,price,dp);
    }
};
int main() { 
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price)/sizeof(price[0]);
    Solution s;
    cout<<s.cutRod(price,n)<<endl;
    return 0;
}