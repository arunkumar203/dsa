//3356
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries){
        int n=nums.size();
        int sum=0,querycount=0;
        vector<int>diff(n+1,0);
        for(int i=0;i<n;i++){
            while(sum+diff[i]<nums[i]){
                querycount++;
                if(querycount>queries.size()) return -1;
                int s=queries[querycount-1][0];
                int e=queries[querycount-1][1];
                int val=queries[querycount-1][2];
                if(e>=i){
                    diff[max(s,i)]+=val;
                    diff[e+1]-=val;
                }
            }
            sum+=diff[i];
        }
        return querycount;
    }
   
    bool cantransform(vector<int>& nums, vector<vector<int>>& queries,int k){
        int n=nums.size();
        int sum=0;
        vector<int>diff(n+1,0);
        for(int i=0;i<k;i++){
            int start=queries[i][0],end=queries[i][1],val=queries[i][2];
            diff[start]+=val;
            diff[end+1]-=val;
    
        }
        for(int i=0;i<n;i++){
            //curr sum indicates the curr total val of all queries
            sum+=diff[i];
            if(sum<nums[i]) return false;
    
        }
        return true;
    
    }
      int minZeroArray2(vector<int>& nums, vector<vector<int>>& queries){
        int n=queries.size();
        int s=0,e=n;
        if(!cantransform(nums,queries,e)) return -1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(cantransform(nums,queries,m)){
                e=m-1;
            }
            else s=m+1;
        }
        return s;
      }
        int minZeroArray1(vector<int>& nums, vector<vector<int>>& queries) {
            int ans=0;
            int temp=0;
            for(auto i:nums){
                if(i>0) temp++;
            }
            if(temp==0) return 0;
            for(auto i:queries){
                int l=i[0];
                int r=i[1];
                int temp1=i[2];
                for(int i=l;i<=r;i++){
                    if(nums[i]>0){
                        if(nums[i]>=temp1) nums[i]-=temp1;
                        else nums[i]=0;
                        if(nums[i]==0) temp--;
                    }
                    
                }
                ans++;
                if(temp==0) return ans;
            }
            return -1;
        }
    };

  
int main(){
        Solution s;
        vector<int>nums={1,2,3,4};
        vector<vector<int>>queries={{0,2,1},{1,3,2}};
        cout<<s.minZeroArray(nums,queries)<<endl;
        cout<<s.minZeroArray1(nums,queries)<<endl;
        return 0;
    }
