//54
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void printSpiral(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int m = matrix.size();        // Number of rows
        int n = matrix[0].size();     // Number of columns
        int top = 0, bottom = m - 1;  // Row boundaries
        int left = 0, right = n - 1;  // Column boundaries
        
        while (top <= bottom && left <= right) {
            // Traverse left to right (top row)
            for (int j = left; j <= right; j++) {
                cout << matrix[top][j] << " ";
            }
            top++;  // Move top boundary down
            
            // Traverse top to bottom (right column)
            for (int i = top; i <= bottom; i++) {
                cout << matrix[i][right] << " ";
            }
            right--;  // Move right boundary left
            
            // if (top <= bottom) {  // Check if there's a row left to traverse
                // Traverse right to left (bottom row)
                for (int j = right; j >= left; j--) {
                    cout << matrix[bottom][j] << " ";
                }
                bottom--;  // Move bottom boundary up
            // }
            
            // if (left <= right) {  // Check if there's a column left to traverse
                // Traverse bottom to top (left column)
                for (int i = bottom; i >= top; i--) {
                    cout << matrix[i][left] << " ";
                }
                left++;  // Move left boundary right
            // }
        }
        cout << endl;  // Newline after spiral
    }
};

// Test the function
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    Solution sol;
    sol.printSpiral(matrix);
    return 0;
}