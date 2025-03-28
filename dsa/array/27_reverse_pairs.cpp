#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int low, int mid, int high) {
    int count = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++) {
        while (j <= high && arr[i] > 2LL * arr[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left++]);
    }
    while (right <= high) {
        temp.push_back(arr[right++]);
    }
int k=0;
    for (int i = low; i <= high; i++) {
        arr[i] = temp[k++];
    }
    return count;
}

int mergeSort(vector<int>& arr, int low, int high) {
    int count = 0;
    if (low < high) {
        int mid = (low + high) / 2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
    }
    return count;
}

int reversePairs(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {1, 3, 2, 3, 1};
    int pairs = reversePairs(arr);
    cout << "Number of reverse pairs: " << pairs << endl;
    return 0;
}
