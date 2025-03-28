#include <bits/stdc++.h>
using namespace std;

int missingBySum(int arr[], int n) {
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }
    return total - sum;
}

int missingByXor(int arr[], int n) {
    int x1 = 0, x2 = 0;
    
    for (int i = 0; i < n - 1; i++) {
        x2 ^= arr[i];  // XOR of array elements
        x1 ^= (i + 1); // XOR of 1 to (n-1)
    }
    x1 ^= n; // Include n in the XOR sequence

    return x1 ^ x2;
}

int main() {
    int arr[] = {3, 4, 1}; // Expected output: 2
    int n = 4;  // Since we are missing one number from 0 to 3, n should be 4.
    
    cout << "Missing Number (Sum Method): " << missingBySum(arr, n) << endl;
    cout << "Missing Number (XOR Method): " << missingByXor(arr, n) << endl;
    
    return 0;
}

//485
//max consecutive ones
int maxConsecutiveOnes(int arr[], int n) {
    int maxCount = 0, currentCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            currentCount++;
        } else {
            maxCount = max(maxCount, currentCount);
            currentCount = 0;
        }
    }
    maxCount = max(maxCount, currentCount);
    return maxCount;
}

//136
//single number
int singleNumber(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}

