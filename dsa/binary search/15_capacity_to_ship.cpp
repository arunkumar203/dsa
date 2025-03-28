//1011
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int curr(vector<int>& weights, int cap){
        int cnt=0;
        int days=1;
        for(auto i:weights){
            if(cnt+i>cap){
                days+=1;
                cnt=i;
            }
            else cnt+=i;
    
        }
        return days;
    }
        int shipWithinDays(vector<int>& weights, int days) {
            int s=*max_element(weights.begin(),weights.end());

            int e=accumulate(weights.begin(),weights.end(),0);
            //for this days=1;
            int ans=0;
            while(s<=e){
                int m=s+(e-s)/2;
                int dayss=curr(weights,m);
                if(dayss<=days){
                    ans=m;
                    e=m-1;
                    //reducing cap will increase days;
                }
                else s=m+1;
            }
            return ans;
    
        }
    };
    
int main() {
    Solution s;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    int ans = s.shipWithinDays(weights, days);
    cout << "Capacity to ship: " << ans << endl;
    return 0;
}
