//189
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
           int n=nums.size();
           k=k%n;
           reverse(nums,0,n-k-1);
           reverse(nums,n-k,n-1);
           reverse(nums,0,n-1);
        }
        void reverse(vector<int>& vec, int start, int end)
        {
            while (start <= end){
                int temp = vec[start];
                vec[start] = vec[end];
                vec[end] = temp;
                start++;
                end--;
                }
        }
    };
    int main(){
        Solution s;
        vector<int>nums={1,2,3,4,5,6,7};
        int k=3;
        s.rotate(nums,k);
        for(auto i:nums){
            cout<<i<<" ";
        }
    }


    //283 //zeros to end
    // #include<bits/stdc++.h>
    // using namespace std;
    // class Solution {
    //     public:
    //         void moveZeroes(vector<int>& nums) {
    //             int i=0;
    //             int k=0;
    //             int n=nums.size();
    //             for(int i=0;i<n;i++){
    //                 if(nums[i]!=0){
    //                     nums[k++]=nums[i];
    //                 }           
    //             }
    //             while(k<n){
    //                 nums[k++]=0;
    //             }
               
    //         }
    //     };
    //     int main(){
    //         Solution s;
    //         vector<int>nums={0,1,0,3,12};
    //         s.moveZeroes(nums);
    //         for(auto i:nums){
    //             cout<<i<<" ";
    //         }
    //     }        

    //union and intersection
    // #include <iostream>
    // #include <vector>
    // using namespace std;
    
    // vector<int> findUnion(vector<int>& arr1, vector<int>& arr2) {
    //     int n1 = arr1.size(), n2 = arr2.size();
    //     int i = 0, j = 0;
    //     vector<int> unionArr;
    
    //     while (i < n1 && j < n2) {
    //         if (arr1[i] < arr2[j]) {
    //             if (unionArr.empty() || unionArr.back() != arr1[i]) 
    //                 unionArr.push_back(arr1[i]);
    //             i++;
    //         } 
    //         else if (arr1[i] > arr2[j]) {
    //             if (unionArr.empty() || unionArr.back() != arr2[j]) 
    //                 unionArr.push_back(arr2[j]);
    //             j++;
    //         } 
    //         else { // arr1[i] == arr2[j]
    //             if (unionArr.empty() || unionArr.back() != arr1[i]) 
    //                 unionArr.push_back(arr1[i]);
    //             i++;
    //             j++;
    //         }
    //     }
    
    //     // Add remaining elements of arr1
    //     while (i < n1) {
    //         if (unionArr.back() != arr1[i]) 
    //             unionArr.push_back(arr1[i]);
    //         i++;
    //     }
    
    //     // Add remaining elements of arr2
    //     while (j < n2) {
    //         if (unionArr.back() != arr2[j]) 
    //             unionArr.push_back(arr2[j]);
    //         j++;
    //     }
    
    //     return unionArr;
    // }
    // vector<int> findIntersection(vector<int>& arr1, vector<int>& arr2) {
    //     int n1 = arr1.size(), n2 = arr2.size();
    //     int i = 0, j = 0;
    //     vector<int> intersectionArr;
    
    //     while (i < n1 && j < n2) {
    //         if (arr1[i] < arr2[j]) 
    //             i++;
    //         else if (arr1[i] > arr2[j]) 
    //             j++;
    //         else { // arr1[i] == arr2[j]
    //             if (intersectionArr.empty() || intersectionArr.back() != arr1[i]) 
    //                 intersectionArr.push_back(arr1[i]);
    //             i++;
    //             j++;
    //         }
    //     }
    //     return intersectionArr;
    // }
    
    
    // int main() {
    //     vector<int> arr1 = {1, 2, 3, 4, 5};
    //     vector<int> arr2 = {2, 3, 5, 6};
    //     vector<int> result = findUnion(arr1, arr2);
    // vector<int> result1 = findUnion(arr1, arr2);


    
    //     cout << "Union: ";
    //     for (int num : result) cout << num << " ";

    // cout << "Intersection: ";
        // for (int num : result1) cout << num << " ";
    //     return 0;
    // }
    
    

