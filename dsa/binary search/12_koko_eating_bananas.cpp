//875
#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int>& v) {
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

long long calculateTotalHours(vector<int>& v, int hourly) {
    long long totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    while (low <= high) {
        int mid = (low + high) / 2;
        long long totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat " << ans << " bananas/hr.\n";
    return 0;
}
