#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(const vector<int>& nums) {
    int ans=1;
    int n=nums.size();
       vector<int>temp;
       temp.push_back(nums[0]);
       for(int i=1;i<n;i++){
        if(nums[i]>temp.back()) {
            temp.push_back(nums[i]);
            ans++;
        }
        else{
            int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[ind]=nums[i];
        }
       }
       return ans;
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    int lis = longestIncreasingSubsequence(arr);

   cout<<lis<<endl;

    return 0;
}