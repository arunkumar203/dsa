#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k;
    cin >> k;
    int a[2 * k];

    for (int i = 0; i < 2 * k; i++) {
        cin >> a[i];
    }

    sort(a, a + (2 * k));

    int c[2 * k] = {0};
    int g = 1, b = 0;
    int s = a[0];

    for (int i = 1; i < 2 * k; i++) {
        if (s == a[i]) {
            g++;
            if (i == (2 * k) - 1) {
                c[b] = g;
            }
        }
        else {
            s = a[i];
            c[b] = g;
            g = 1;
            b++;
            if (i == (2 * k) - 1) {
                c[b] = g;
            }
        }
    }

    int* m = max_element(c, c + (2 * k));
    cout << *m << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
