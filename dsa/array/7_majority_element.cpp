//169
#include<bits/stdc++.h>
using namespace std;
int majorityElementMap(const vector<int>& nums) {
    unordered_map<int, int> countMap;
    for(int num : nums) {
        countMap[num]++;
    }
    for(auto& [val, freq] : countMap) {
        if(freq > nums.size() / 2) return val;
    }
    return -1;
}

int majorityElementMoore(const vector<int>& nums) {
    int candidate = -1, count = 0;
    for(int num : nums) {
        if(count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}