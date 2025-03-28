//774
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& stations, int k, double mid) {
        int count = 0;
        for (int i = 1; i < stations.size(); i++) {
            count += (int)((stations[i] - stations[i - 1]) / mid);
        }
        return count <= k;
    }
    double minmaxGasDist(vector<int>& stations, int k) {
        double s = 0;
        double e = stations.back() - stations[0];
        double ans = e;
        double diff = 1e-6;
        while (e - s > diff) {
            double mid = s + (e - s) / 2;
            if (isPossible(stations, k, mid)) {
                ans = mid;
                e = mid;
            } else {
                s = mid;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> stations = {1, 2, 3, 4, 5};
    int k = 4;
    double ans = s.minmaxGasDist(stations, k);
    cout << "Minimum maximum distance: " << ans << endl;
    return 0;
}
