#include <bits/stdc++.h>
using namespace std;

// 2-pointer approach (requires sorted array)


// unordered_map approach (does not require sorting)
// pair<int,int> twoSumMap(vector<int>& arr, int target) {
//     unordered_map<int,int> m;
//     for (int i = 0; i < (int)arr.size(); i++) {
//         int complement = target - arr[i];
//         if (m.find(complement) != m.end()) {
//             return {m[complement], i};
//         }
//         m[arr[i]] = i;
//     }
//     return {-1, -1};
// }
pair<int, int> twoSumMap(vector<int>& arr, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < (int)arr.size(); i++) {
        int complement = target - arr[i];
        if (m.find(complement) != m.end()) {
            return {m[complement], i}; // Found the correct pair
        }
        m[arr[i]] = i; // Store index of the current number
    }
    return {-1, -1}; // No valid pair found
}


int main(){
    // vector<int> arr = {2, 10, 11, 15,8,4,1};
    // int target = 9;
    // unordered_map<int,int> mp;
    // for (int i = 0; i < (int)arr.size(); i++) {
    //     mp[arr[i]] = i;
    // }
    // sort(arr.begin(), arr.end());
    // int l = 0, r = arr.size() - 1;
    // while (l < r) {
    //     int s = arr[l] + arr[r];
    //     if (s == target) {
    //         cout << mp[arr[l]] << " " << mp[arr[r]] << endl;
    //         return 0;
    //     } else if (s < target) {
    //         l++;
    //     } else {
    //         r--;
    //     }
    // }
    // cout << -1 << " " << -1 << endl;

    vector<int> arr = {2, 10, 11, 15,8,4,1};
    int target = 9;
    pair<int,int> result = twoSumMap(arr, target);
    cout << result.first << " " << result.second << endl;
    return 0;
    

    
}