#include<bits/stdc++.h>
using namespace std;

bool isvalid(int row, int col, vector<vector<int>>& board, int k) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == k || board[i][col] == k) {
            return false;
        }
    }

    int temprow = (row / 3) * 3;
    int tempcol = (col / 3) * 3;
    for (int i = temprow; i < temprow + 3; i++) {
        for (int j = tempcol; j < tempcol + 3; j++) {
            if (board[i][j] == k) {
                return false;
            }
        }
    }

    return true;
}

bool  solve(vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {
                    if (isvalid(i, j, board, k)) {
                        board[i][j] = k;
                        if (solve(board)) {
                            return true;
                        } else {
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solve(board)) {
        cout << "Sudoku Solved:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
