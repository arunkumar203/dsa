#include<bits/stdc++.h>
// using namespace std;

// void find(int ind,  vector<int>& ans, vector<int>& num,int sum) {
//     ans.push_back(sum);

//     for (int i = ind; i < num.size(); i++) {
//         find(i + 1, ans, num,sum+num[i]);
//     }
// }

// vector<int> subsetSum(vector<int>& num) {
//     vector<int> ans;
//     find(0, ans, num,0);
//     return ans;
// }

// int main() {
//     vector<int> a = {1, 2, 3};
//     vector<int> final = subsetSum(a);
//     sort(final.begin(),final.end());
//     for (auto it : final) {
//         cout<<it<<" ";
//     }

//     return 0;
// }