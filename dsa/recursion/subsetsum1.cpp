#include<bits/stdc++.h>
using namespace std;

void find(int ind, vector<int>& ans, vector<int>& num, int sum) {
    if (ind == num.size()) {
        ans.push_back(sum);
        return;
    }

    find(ind + 1, ans, num, sum + num[ind]);
    find(ind + 1, ans, num, sum);
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
    vector<int> ans;
    find(0, ans, num, 0);
	// sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<int> a= {1, 2, 3};
    vector<int> ds;
    vector<int> ans=subsetSum(a);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
//2nd method
// #include<bits/stdc++.h>
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
