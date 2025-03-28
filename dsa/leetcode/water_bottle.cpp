#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int find(int n,int k){
    if(n<k) return 0;
    //here n is number of empty bottles
    int ans=n/k;
    return ans+find(n/k+n%k,k);
    
}
   
    int numWaterBottles1(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            int temp=numBottles/numExchange;
            ans+=temp;
            int toadd=numBottles%numExchange;
            numBottles=temp+toadd;
        }
        return ans;
    }
};
int main() {
    Solution s;
    int numBottles = 9;
    int numExchange = 3;
    int result1 = s.numWaterBottles1(numBottles, numExchange);
    int result2 = numBottles+s.find(numBottles, numExchange);
    cout << "Total number of water bottles: " << result1 << endl;
    cout << "Total number of water bottles: " << result2 << endl;
    return 0;
}