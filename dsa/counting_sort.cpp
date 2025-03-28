#include <bits/stdc++.h>
using namespace std;

void counting(int a[], int n) {
    int lar = 0;
    for (int i = 0; i < n; i++) {
        lar = max(lar, a[i]);
    }
    int b[lar+1]={0};  

    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }

    int loc = 0;
    for (int i = 0; i <= lar; i++) {
        int k = b[i];
        for (int j = 0; j < k; j++) {
            a[loc] = i;
            loc++;
        }
    }

}

int main() {
    int a[] = {1, 3, 4, 5, 6, 1, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);

    counting(a, n);

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}
