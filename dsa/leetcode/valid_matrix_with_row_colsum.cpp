//1605
//rowsum[i] represents sum of elements in ith row
//colsum[j] represents sum of elements in jth column
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size();
        int n=colSum.size();
        int i=0,j=0;
        vector<vector<int>>ans(m,vector<int>(n,0));
        while(i<m&&j<n){
            ans[i][j]=min(rowSum[i],colSum[j]);
            rowSum[i]-=ans[i][j];
            colSum[j]-=ans[i][j];
            if(rowSum[i]==0) i++;
            if(colSum[j]==0) j++;
        }
        return ans;
    }
};
int main(){
    vector<int>rowSum={5,7,10};
    vector<int>colSum={8,6,8};
    Solution s;
    vector<vector<int>>ans=s.restoreMatrix(rowSum,colSum);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}