//88
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i=m-1,j=n-1,k=m+n-1;
    while(j>=0){
        if(i>=0 && nums1[i]>=nums2[j]){
            nums1[k]=nums1[i];
            i--;
        } 
        else{
            nums1[k]=nums2[j];
            j--;
        }
        k--;
    }
}
int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m=3,n=3;
    merge(nums1,m,nums2,n);
    for(auto x:nums1){
        cout<<x<<" ";
    }
    return 0;
}