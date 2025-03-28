#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m) {
  int low = 1, high = m;
  while (low <= high) {
    int mid = (low + high) / 2;
    long long int midN = 1;
    for (int i = 0; i < n; i++) {
      midN *= mid;
      if (midN > m) break;
    }
    if (midN == m) return mid;
    else if (midN < m) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}

int main() {
  int n = 3, m = 27;
  int ans = NthRoot(n, m);
  cout << "The answer is: " << ans << "\n";
  return 0;
}
