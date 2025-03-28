#include <bits/stdc++.h>
using namespace std;

long long countSubarraysWithXOR(vector<int>& arr, int k) {
    unordered_map<int, int> xorFreq; // Maps prefix XOR to its frequency
    xorFreq[0] = 1;                  // Empty subarray has XOR 0
    int currXor = 0;                 // Running XOR
    long long count = 0;             // Number of subarrays with XOR = k
    
    for (int num : arr) {
        currXor ^= num;              // Update running XOR
        int needed = currXor ^ k;    // Prefix XOR needed to make currXor ^ needed = k
        if (xorFreq.find(needed) != xorFreq.end()) {
            count += xorFreq[needed]; // Add frequency of needed XOR
        }
        xorFreq[currXor]++;          // Increment frequency of current XOR
    }
    
    return count;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << countSubarraysWithXOR(arr, k) << "\n"; // Output: 4
    return 0;
}