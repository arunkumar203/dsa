//1529
//you are given a 0-indexed binary string target of length n. 
//You have another binary string s of length n that is initially set to all zeros. You want 
//to make s equal to target.

//start from 1st index
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(string target) {
        int ans=0;
        int n=target.size();
        for(int i=0;i<n;i++){
            int curr=target[i]-'0'; //curr val of target[i]
            int state=ans%2;//curr val of s[i]
            if(curr!=state) ans++;
        }
        return ans;
    }
};
int main(){
    string target="10111";
    Solution s;
    cout<<s.minFlips(target)<<endl;
}

//----------------------------
//tweaked version of above q is 3192
//Minimum Operations to Make Binary Array Elements Equal to One II
//Return the minimum number of operations required to make all elements in nums equal to 1.
//can be assumed like intial all 1s and needs to be converted  to target 



// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         int ans=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             int curr=nums[i];
//             int state=(ans+1)%2;
//             if(curr!=state) ans++;
//         }
//         return ans;
//     }
// };
//intially ans is 0,state should be 1 so it is ans+1

