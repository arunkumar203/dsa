//2594
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool find(vector<int>&ranks,int cars,long long m){
        long long cnt=0;
        for(int i=0;i<ranks.size();i++){
            cnt+=sqrt((m*1.0)/(ranks[i]));
        }
        return cnt>=cars*1ll;
    }
        long long repairCars(vector<int>& ranks, int cars) {
            long long s=1;
            int n=ranks.size();
            int maxi=*max_element(ranks.begin(),ranks.end());
            //mech with largesr rank will get max cars(others with 0)
            long long e=1ll*maxi*cars*cars;
            long long ans=0;
            while(s<=e){
                long long m=s+(e-s)/2;
                if(find(ranks,cars,m)){
                    ans=m;
                    e=m-1;
                }
                else{
                    s=m+1;
                }
            }
            return ans;
        }
    };
    
int main(){
    Solution s;
    vector<int>ranks={4,2,3,1};
    int cars=10;
    cout<<s.repairCars(ranks,cars)<<endl;
    return 0;
}
