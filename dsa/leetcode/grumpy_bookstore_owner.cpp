#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int temp=0;
        for(int i=0;i<minutes;i++){
            temp+=customers[i]*grumpy[i];
        }
        int maxi=temp;//if we initialse maxi=0 after temp=0,it will fail a case where 1st windows is correct
        int i=0;
        int j=minutes;
        while(j<n){
            temp+=customers[j]*grumpy[j];
            temp-=customers[i]*grumpy[i];
            maxi=max(temp,maxi);
            i++;
            j++;
        }
        int ans=maxi;
        for(int i=0;i<n;i++){
            ans+=customers[i]*(1-grumpy[i]);
        }
        return ans;
    }
};
int main() {
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;
    //customers are not satisfied if owner is grumpy and owner knows to keep ungrumpy for k minutes,
    // return max satisfied customers
    Solution obj;
    int maxSatisfied = obj.maxSatisfied(customers, grumpy, minutes);
    cout << "Maximum number of satisfied customers: " << maxSatisfied << endl;

    return 0;
}