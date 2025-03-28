#include <iostream>
#include <vector>
using namespace std;

int largest(const vector<int>& arr) {
    int maxVal = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int secondLargest(const vector<int>& arr) {
    int first = arr[0], second = -1;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        } else if(arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    return second;
}

bool isSorted(const vector<int>& arr) {
    // for(int i = 1; i < arr.size(); i++){
    //     if(arr[i] < arr[i-1]) return false;
    // }
    // return true;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]) return false;
    }
    return true;
}
bool sortedrotated(vector<int>& arr){
    int temp=0,n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]>arr[(i+1)%n]){
            temp++;
        }
    }
    return temp<=1;
}
int removeDuplicates(vector<int>&nums){
    int n=nums.size();
    int k=1;
    for(int i=1;i<n;i++){
        if(nums[i]!=nums[k-1]){
            nums[k]=nums[i];
            k++;
        }
    }
    return k;
}

int main(){
    vector<int> arr{10,10,10, 20, 20, 5, 30};
    cout << "Largest: " << largest(arr) << endl;
    cout << "2nd Largest: " << secondLargest(arr) << endl;
    cout << "Is Sorted: " << (isSorted(arr) ? "Yes" : "No") << endl;
    cout << "Is Sorted Rotated: " << (sortedrotated(arr) ? "Yes" : "No") << endl;
    vector<int> arr1{1,1,2,2,3,3,4,4,5,5};
    cout << "Remove Duplicates: " << removeDuplicates(arr1) << endl;


    return 0;
}