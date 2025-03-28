#include<bits/stdc++.h>
using namespace std;
#define line printf("\n");

void prefixsum(int a[][6], int n) {
    int prefix[6][6] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0 && j > 0) {
                int k=a[i][j];
                prefix[i][j] = k+prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
            } else {
                if (i == 0 && j == 0) {
                    prefix[0][0] = 0;
                } else if (i == 0 && j != 0) {
                    prefix[i][j] = prefix[0][j - 1] + a[0][j];
                } else if (i != 0 && j == 0) {
                    prefix[i][j] = prefix[i - 1][0] + a[i][0];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << prefix[i][j] << " ";
        }
        line
    }

    int ls = 0;
    int x=0,y=0;
    int k1 = 0, k2 = 0, k3 = 3, k4 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            k1 = prefix[i][j];
            k2 = prefix[i][5] - k1;
            k3 = prefix[5][j] - k1;
            k4 = prefix[5][5] - k1 - k2 - k3;
            // if (k1 == 0 || k2 == 0 || k3 == 0 || k4 == 0) {
            //     continue;
            // }

            int k = min({k1, k2, k3, k4});

            if (k > ls) {
                ls = k;
                x=i;
                y=j;
            }
        }
    }

    cout << ls << endl;
    cout<<"at " << x <<"and"<<y<< endl;
}

int main() {
    int a[6][6] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1},
        {1, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0}
    };

    prefixsum(a, 6);

    return 0;
}
