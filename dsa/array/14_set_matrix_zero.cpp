//73
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int rows = matrix.size();
            if (rows == 0) return;
            int cols = matrix[0].size();
            bool firstRowHasZero = false;
            bool firstColHasZero = false;
            for (int col = 0; col < cols; col++) {
                if (matrix[0][col] == 0) {
                    firstRowHasZero = true;
                    break;
                }
            }
            for (int row = 0; row < rows; row++) {
                if (matrix[row][0] == 0) {
                    firstColHasZero = true;
                    break;
                }
            }
            for (int row = 1; row < rows; row++) {
                for (int col = 1; col < cols; col++) {
                    if (matrix[row][col] == 0) {
                        matrix[row][0] = 0; 
                        matrix[0][col] = 0; 
                    }
                }
            }
            for (int row = 1; row < rows; row++) {
                for (int col = 1; col < cols; col++) {
                    if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                        matrix[row][col] = 0;
                    }
                }
            }
            if (firstRowHasZero) {
                for (int col = 0; col < cols; col++) {
                    matrix[0][col] = 0;
                }
            }
            
            if (firstColHasZero) {
                for (int row = 0; row < rows; row++) {
                    matrix[row][0] = 0;
                }
            }
        }
    };
    int main(){
        Solution s;
        vector<vector<int>>matrix={{1,1,1},{1,0,1},{1,1,1}};
        s.setZeroes(matrix);
        for(auto i:matrix){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }    