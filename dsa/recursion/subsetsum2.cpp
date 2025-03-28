#include<bits/stdc++.h>
using namespace std;

void find(int ind,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums){
        ans.push_back(ds);

    for(int i=ind;i<nums.size();i++){
        if(i>ind && nums[i]==nums[i-1]){
            continue;
        }
        ds.push_back(nums[i]);
        find(i+1,ds,ans,nums);
        ds.pop_back();
    }
}
    vector<vector<int>> subsetsum2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        find(0,ds,ans,nums);
        return ans;
    }

int main() {
  vector<int> nums={1,2,2};
    vector<vector<int>> result = subsetsum2(nums);

    for (auto& subset : result) {
        for (auto& num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

