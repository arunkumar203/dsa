#include <bits/stdc++.h>
using namespace std;

int binary(int a[], int n, int k) {
    int s = 0, e = n - 1;
    int mid = (s + e) / 2;
    while (s <= e) {
        if (a[mid] == k) {
            return mid;
        } else if (a[mid] > k) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = (s + e) / 2; 
    }
    return -1;
}

int main() {
    int a[] = {10, 20, 30, 40, 50, 65, 78, 89, 90};
    int n = sizeof(a) / sizeof(a[0]);
    int k;
    cin >> k;
    int c = binary(a, n, k);
    if (c == -1) {
        cout << "not found" << endl;
    } else {
        cout << "found at " << c << endl;
    }
    return 0;
}
