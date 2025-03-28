//1497
//Given an array of integers arr of even length n and an integer k.
//We want to divide the array into exactly n / 2 pairs such that the sum of 
//each pair is divisible by k.
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool canArrange(vector<int>& arr, int k) {
            vector<int>freq(k,0);
            for(auto i:arr){
                // int remain=i%k;
                // if(remain<0) remain+=k;
                // if(i>=0) freq[i%k]++;
                freq[(((i%k)+k)%k)]++;
                // freq[remain]++;
                
            }
            if(freq[0]%2==1) return false;
            for(int i=1;i<=k/2;i++){
                if(freq[i]!=freq[k-i]) return false;
            }
            return true;
        }
    };
    int main(){

    }