#include <bits/stdc++.h>
using namespace std;

void reverse(int a[], int n) {
    int s = 0, e = n - 1;
    int mid = (s + e) / 2;
    while (s <= e) {
       swap(a[s], a[e]);
       s++;
       e--;

    }
   
}

int main() {
    int a[] = {10, 20, 30, 40, 50, 65, 78, 89, 90};
    int n = sizeof(a) / sizeof(a[0]);
    reverse(a,n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}
