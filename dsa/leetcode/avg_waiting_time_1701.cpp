//1701. Average Waiting Time
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double curr=0;
        double ans=0;
        for(int i=0;i<customers.size();i++){
            if(curr<customers[i][0]) curr=customers[i][0]; //if the chef is free before the customer arrives
            ans=ans+curr+customers[i][1]-customers[i][0];
            curr=curr+customers[i][1];
        }
        return ans/customers.size();
    }
};
int main(){
    Solution s;
    vector<vector<int>> customers={{5,2},{5,4},{10,3},{20,1}};
    cout<<s.averageWaitingTime(customers);
}