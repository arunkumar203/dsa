//34
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstOccurance(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return first;
    }

    int lastOccurance(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int last = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurance(nums, target);
        int last = lastOccurance(nums, target);
        return {first, last};
    }
};
int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> ans = s.searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}


//lb=lower_bound(target)
//if(lb==n || nums[lb]!=target) return {-1,-1};
//ub=upper_bound(target)
//return {lb,up-1};
