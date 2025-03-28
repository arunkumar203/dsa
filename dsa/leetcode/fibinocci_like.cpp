//873
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int find(int j,int k,unordered_map<int,int>&mp,vector<int>&arr){
        int target=arr[k]-arr[j];
        if(mp.count(target) && mp[target]<j){
            int i=mp[target];
            return find(i,j,mp,arr)+1;
        }
        return 2;
    }
        int lenLongestFibSubseq(vector<int>& arr) {
            int n=arr.size();
            unordered_map<int,int>mp;
            for(int i=0;i<n;i++){
                mp[arr[i]]=i;
            }
            // int ans=0;
            // for(int j=0;j<n;j++){
            //     for(int k=j+1;k<n;k++){
            //         int temp=find(j,k,mp,arr);
            //         if(temp>=3) ans=max(temp,ans);
    
            //     }
            // }
            // return ans;
    
            int ans=0;
            vector<vector<int>>dp(n,vector<int>(n,2));
            for(int j=0;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int target=arr[k]-arr[j];
                    if(mp.count(target)&&mp[target]<j) {
                        int i=mp[target];
                        dp[j][k]=dp[i][j]+1;
                        ans=max(ans,dp[j][k]);
                    }
        
                }
            }
            return ans>=3?ans:0;
    
    
    
        }
    };
    int main(){
        Solution s;
        vector<int>arr={1,3,7,11,12,14,18};
        cout<<s.lenLongestFibSubseq(arr)<<endl;
        return 0;
    }

