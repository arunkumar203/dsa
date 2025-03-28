#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    int rowWithMax1s(vector<vector<int>> &matrix, int m, int n) {
        int max_ones = 0, row_index = -1;
        for (int i = 0; i < m; i++) {
            int lb = lowerBound(matrix[i], n, 1);
            int ones = n - lb;
            if (ones > max_ones) {
                max_ones = ones;
                row_index = i;
            }
        }
        return row_index;
    }
};

void runTestCases() {
    vector<vector<int>> test1 = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    vector<vector<int>> test2 = {{0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}};
    vector<vector<int>> test3 = {{0, 0, 0}, {0, 0, 1}, {0, 1, 1}, {1, 1, 1}};
    
    Solution s;
    cout << "Test Case 1: " << s.rowWithMax1s(test1, 4, 4) << " (Expected: 2)" << endl;
    cout << "Test Case 2: " << s.rowWithMax1s(test2, 4, 4) << " (Expected: 3)" << endl;
    cout << "Test Case 3: " << s.rowWithMax1s(test3, 4, 3) << " (Expected: 3)" << endl;
}

int main() {
    
    
    
    
    cout << "Running Test Cases...\n";
    runTestCases();
    
    return 0;
}
