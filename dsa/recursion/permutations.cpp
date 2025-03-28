//1st methosd
#include<bits/stdc++.h>
using namespace std;

    void find( vector<int>& ds,  vector< vector<int>>& ans, vector<int>& nums,  vector<int>& freq) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                find(ds, ans, nums, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

     vector< vector<int>> permute( vector<int>& nums) {
         vector< vector<int>> ans;
         vector<int> ds;
         vector<int> freq(nums.size(), 0);
        find(ds, ans, nums, freq);
        return ans;
    }
int main(){
    vector<int>nums={1,2,4};
    vector<vector<int>> final=permute(nums);
    for(auto it:final){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

//2nd method uses no extra space 
#include<bits/stdc++.h>
using namespace std;
void find(int ind,  vector< vector<int>>& ans, vector<int>& nums) {
       if(ind==nums.size()){
           ans.push_back(nums);
           return;
       }
       for(int i=ind;i<nums.size();i++){
              swap(nums[i],nums[ind]);
               find(ind+1,ans,nums);
               swap(nums[i],nums[ind]);
               
         
       }
    }

     vector< vector<int>> permute( vector<int>& nums) {
         vector< vector<int>> ans;
        find(0, ans, nums);
        return ans;
    }
int main(){
    vector<int>nums={1,2,3};
    vector<vector<int>> final=permute(nums);
    for(auto it:final){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

//just print instaed of storing permutation

#include<bits/stdc++.h>
using namespace std;
void find(int ind,vector<int>&a){
    if(ind==a.size()){
        for(auto it:a){
        cout<<it<<" ";
    }
      cout<<endl;
    }
  
    for(int i=ind;i<a.size();i++){
        swap(a[i],a[ind]);
        find(ind+1,a);
        swap(a[i],a[ind]);
    }
}
int main(){
    vector<int> a={1,2,3};
    find(0,a);
}
