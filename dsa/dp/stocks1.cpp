//121
//buy and cell only once 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int find(vector<int>a,int n){
    int mini=a[0];
    int ans=0;
    for(int i=0;i<n;i++){
        int cost=a[i]-mini;
        ans=max(ans,cost);
        mini=min(mini,a[i]);
    }
    return ans;
}
    int maxProfit(vector<int>& prices) {
        return find(prices,prices.size());
        // if(prices.size()<2) return 0;
        // int temp=INT_MAX;
        // vector<int>mintill(prices.size(),0);
        // for(int i=0;i<prices.size();i++){
        //     mintill[i]=min(temp,prices[i]);
        //     temp=mintill[i];
        // }
        // for(int i=0;i<prices.size();i++){
        //     cout<<mintill[i]<<" ";
        // }
        // int ans=INT_MIN;
        // for(int i=1;i<prices.size();i++){
        //     ans=max(ans,prices[i]-mintill[i]);
        // }
        // return ans;
    }
};
int main(){
    vector<int>prices={7,1,5,3,6,4};
    Solution obj;
    cout<<obj.maxProfit(prices)<<endl;
    return 0;
}