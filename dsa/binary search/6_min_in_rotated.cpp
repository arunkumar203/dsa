//153
#include <bits/stdc++.h>
using namespace std;


int findMin(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    
    // If not rotated or single element, return first
    if (nums[left] <= nums[right]) return nums[0];
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1; // Min is in right half
        } else {
            right = mid;    // Min is in left half or at mid
        }
    }
    return nums[left]; // Left lands on minimum
}

int findMin1(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // the left part is sorted:
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else { //if right part is sorted:
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}
