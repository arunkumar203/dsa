//69
#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n)
{
    int s = 0, e = n;
    long long int ans = -1;
    while (s <= e)
    {
        long long int mid = s + (e - s) / 2;
        long long int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 40;
    int ans = floorSqrt(n);
    cout << "The floor of the square root of " << n << " is: " << ans << "\n";
    return 0;
}
