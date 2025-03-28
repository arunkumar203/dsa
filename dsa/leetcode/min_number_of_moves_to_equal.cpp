#include<bits/stdc++.h>
using namespace std;
//incrementing n-1 elements by 1 is same as decrementing 1 element by 1
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;;
        for(auto i:nums){
            mini=min(mini,i);
        }
        int ans=0;
        for (int i:nums) {
            ans+=i-mini;
        }
        return ans;
    }
};
int main(){
     vector<int> nums = {1, 2, 3, 4, 5};
    Solution solution;
    //to make all elements equal in each move n-1 elements are incremented by 1
    int moves = solution.minMoves(nums);
    cout << "Minimum number of moves to make all elements equal: " << moves << endl;
    
}