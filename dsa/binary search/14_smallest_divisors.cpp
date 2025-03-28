//1283
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    long long sum1(vector<int>&nums,int div){
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil(double(nums[i])/double(div));
        }
        return sum;
    }
        int smallestDivisor(vector<int>& nums, int threshold) {
            int s=1;
            int e=*max_element(nums.begin(),nums.end());
            int ans=0;
            while(s<=e){
                int m=s+(e-s)/2;
                if(sum1(nums,m)<=threshold){
                    e=m-1;
                    ans=m;
                }
                else{
                    s=m+1;
                }
            }
            return ans;
        }
    };
    
int main() {
    Solution s;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    int ans = s.smallestDivisor(nums, threshold);
    cout << "Smallest divisor: " << ans << endl;
    return 0;
}
