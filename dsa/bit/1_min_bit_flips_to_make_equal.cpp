#include <iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        int count = 0;
        while (n > 0) {
            if (n & 1) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
};

int main() {
    Solution s;
    int start = 10, goal = 7;
    cout << "Minimum bit flips: " << s.minBitFlips(start, goal) << endl;
    return 0;
}
