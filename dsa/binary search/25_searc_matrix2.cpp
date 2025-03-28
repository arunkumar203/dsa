//240
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m-1, j = 0;
        while (i >= 0&& j <n) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] >target) {
                i--;
            } else {
                j++;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;
    cout << "Target " << target << " found: " << s.searchMatrix(matrix, target) << endl;
    target = 20;
    cout << "Target " << target << " found: " << s.searchMatrix(matrix, target) << endl;
    return 0;
}
