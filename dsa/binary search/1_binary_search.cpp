#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevent potential overflow
        if (arr[mid] == target) {
            return mid; // Target found at index mid
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    int result = binarySearch(arr, target);
    if (result == -1) {
        cout << "Element is not present in array" << endl;
    } else {
        cout << "Element is present at index " << result << endl;
    }
    return 0;
}
