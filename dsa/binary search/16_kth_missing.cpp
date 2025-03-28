//1539
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int s=0,e=arr.size()-1;
            while(s<=e){
                int m=s+(e-s)/2;
                int miss=arr[m]-(m+1);
                if(miss<k) s=m+1;
                else e=m-1;
            }
            return k+s;
        }
    };
    
int main() {
    Solution s;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    int ans = s.findKthPositive(arr, k);
    cout << "Kth missing positive number: " << ans << endl;
    return 0;
}
