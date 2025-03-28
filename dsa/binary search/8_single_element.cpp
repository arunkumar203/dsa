//540
#include <bits/stdc++.h>
using namespace std;


int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    
 
    if (n == 1) return nums[0];
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mid % 2 == 1) mid--; 
        
        if (nums[mid] == nums[mid + 1]) {
            left = mid + 2; 
        } else {
            right = mid;   
        }
    }
    return nums[left]; 
}
int singleNonDuplicate1(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 2] != arr[n - 1]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            return arr[mid];
        }

        // We are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}
