#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2, 1};
    cout << "Single number: " << s.singleNumber(nums) << endl;
    return 0;
}
