#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    string c;
    cin >> c;
    char B = 'B';
    char G = 'G';
    char h;
    while (n--)
    {
        for (int i = 0; i < m; i++)
        {
            if (c[i] == B and c[i + 1] == G)
            {
                h = c[i];
                c[i] = c[i + 1];
                c[i + 1] = h;
                i++;
            }
        }
    }
    cout << c;
    return 0;
}