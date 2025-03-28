//162
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n=nums.size();
    int s=0,e=n-1;
    if(n==1) return 0;
    while(s<e){
        int m=s+(e-s)/2;
        if(nums[m]<nums[m+1]){
            s=m+1;
        } 
        else{
            e=m;
        } 
    }
    return s;
}
int findPeakElement1(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }

        if (arr[mid] > arr[mid - 1]) {
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
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}
