#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countInversions(vector<int>& arr, int low, int mid, int high) {
        long long count = 0;
        int right = mid + 1;

        // Count inversions before merging
        for (int left = low; left <= mid; left++) {
            while (right <= high && arr[left] > arr[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }

        // Merge step (same as merge sort)
        vector<int> temp;
        int left = low, r = mid + 1;
        while (left <= mid && r <= high) {
            if (arr[left] <= arr[r]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[r++]);
            }
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (r <= high) temp.push_back(arr[r++]);

        int k = 0;
        for (int i = low; i <= high; i++) {
            arr[i] = temp[k++];
        }

        return count;
    }

    long long mergeSort(vector<int>& arr, int low, int high) {
        long long count = 0;
        if (low < high) {
            int mid = (low + high) / 2;
            count += mergeSort(arr, low, mid);
            count += mergeSort(arr, mid + 1, high);
            count += countInversions(arr, low, mid, high);
        }
        return count;
    }

    long long countInversions(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 3, 2, 1, 4};
    cout << "Number of inversions: " << sol.countInversions(nums) << endl;
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// long long merge(vector<int>& arr, int low, int mid, int high) {
//     vector<int> temp;
//     int left = low;
//     int right = mid + 1;
//     long long count = 0;
//     while (left <= mid && right <= high) {
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         } else {
//             temp.push_back(arr[right]);
//             count += (mid - left + 1);
//             right++;
//         }
//     }

//     while (left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }

//     while (right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }
// int k=0;
//     for (int i = low; i <= high; i++) {
//         arr[i] = temp[k++];
//     }
//     return count;
// }

// long long mergeSort(vector<int>& arr, int low, int high) {
//     long long count = 0;
//     if (low < high) {
//         int mid = (low + high) / 2;
//         count += mergeSort(arr, low, mid);
//         count += mergeSort(arr, mid + 1, high);
//         count += merge(arr, low, mid, high);
//     }
//     return count;
// }

// long long countInversions(vector<int>& arr) {
//     return mergeSort(arr, 0, arr.size() - 1);
// }

// int main() {
//     vector<int> arr = {5, 3, 2, 1, 4};
//     long long inversions = countInversions(arr);
//     cout << "Number of inversions: " << inversions << endl;
//     return 0;
// }


