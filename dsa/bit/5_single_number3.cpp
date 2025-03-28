//260
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        // int rightmostSetBit = xorSum & -xorSum;
        int rightmostSetBit=(xorSum& (xorSum-1) )^(xorSum);
        int xor1 = 0, xor2 = 0;
        for (int num : nums) {
            if (num & rightmostSetBit) {
                xor1 ^= num;
            } else {
                xor2 ^= num;
            }
        }
        return {xor1, xor2};
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> result = s.singleNumber(nums);
    cout << "Single numbers: " << result[0] << ", " << result[1] << endl;
    return 0;
}
