#include <iostream>
#include <vector>
using namespace std;

void findMissingRepeating(vector<int>& arr) {
    int n = arr.size();
    
    // Step 1: Compute expected sum and sum of squares
    long long S1 = (long long)n * (n + 1) / 2;
    long long S2 = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long S_arr = 0, S2_arr = 0;

    // Step 2: Compute actual sum and sum of squares from the array
    for (int num : arr) {
        S_arr += num;
        S2_arr += (long long)num * num;
    }

    // Step 3: Compute missing - repeating and (missing^2 - repeating^2)
    long long diff = S1 - S_arr;       // X - Y
    long long sum_diff = S2 - S2_arr;  // X^2 - Y^2

    // Step 4: Solve for X and Y
    long long sum = sum_diff / diff;  // X + Y

    int missing = (diff + sum) / 2;
    int repeating = sum - missing;

    cout << "Repeating: " << repeating << ", Missing: " << missing << endl;
}

int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1};  // Example: Repeating = 1, Missing = 5
    findMissingRepeating(arr);
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// pair<int, int> findMissingRepeatingNumbers(vector<int>& a) {
//     int n = a.size();
//     vector<int> hash(n + 1, 0);
//     int repeating = -1, missing = -1;

//     for (int i = 0; i < n; i++) {
//         hash[a[i]]++;
//     }

//     for (int i = 1; i <= n; i++) {
//         if (hash[i] == 2) repeating = i;
//         else if (hash[i] == 0) missing = i;

//         if (repeating != -1 && missing != -1) break;
//     }

//     return {repeating, missing};
// }

// int main() {
//     vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
//     pair<int, int> ans = findMissingRepeatingNumbers(a);
//     cout << "Repeating Number: " << ans.first << endl;
//     cout << "Missing Number: " << ans.second << endl;
//     return 0;
// }


