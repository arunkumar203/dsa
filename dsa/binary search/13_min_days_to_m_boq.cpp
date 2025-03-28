//1482
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool find(vector<int>&nums,int mid,int m,int k){
        int n=nums.size();
        int cnt=0;
        int blooms=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                cnt++;
            }
            else{
                blooms+=cnt/k;
                cnt=0;
            }
        }
        blooms+=cnt/k;
        return blooms>=m;
    }
        int minDays(vector<int>& bloomDay, int m, int k) {
            int s=*min_element(bloomDay.begin(),bloomDay.end());
            int e=*max_element(bloomDay.begin(),bloomDay.end());
            long long n=bloomDay.size();
            if(n<(1ll*m*k)) return -1;
            long long ans=0;
            while(s<=e){
                long long mid=s+(e-s)/2;
                if(find(bloomDay,mid,m,k)){
                    e=mid-1;
                    ans=mid;
                }
                else s=mid+1;
            }
            return ans;
        }
    };
   
int main() {
    Solution s;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    int ans = s.minDays(bloomDay, m, k);
    cout << "Minimum days: " << ans << endl;
    return 0;
}

