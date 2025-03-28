//18
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size() - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < (int)nums.size() - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1, right = (int)nums.size() - 1;
            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 1;
    auto result = fourSum(nums, target);
    for (auto &v : result) {
        for (auto &x : v) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
