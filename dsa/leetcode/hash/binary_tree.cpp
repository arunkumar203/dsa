//823
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numFactoredBinaryTrees(vector<int>& arr) {
            sort(arr.begin(),arr.end());
            unordered_map<int,long long>mp;
            mp[arr[0]]=1;
            int n=arr.size();
            for(int i=1;i<n;i++){
                int root=arr[i];
                mp[root]=1;
                for(int j=0;j<i;j++){
                    int lc=arr[j];
                    if(root%lc==0 && mp.find(arr[i]/lc)!=mp.end()){
                        mp[root]+=mp[lc]*mp[arr[i]/lc];
                    }
                }
            }
            long long ans=0;
            for(auto i:mp){
                ans+=i.second;
            }
            return ans%(long long)(1e9+7);
    
        }
    };
    int main(){
        Solution s;
        vector<int>arr={2,4,5,10};
        cout<<s.numFactoredBinaryTrees(arr)<<endl;
    }