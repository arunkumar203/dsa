#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 4; // Number of rows on the board
const int COLS = 4; // Number of columns on the board
const int TARGET = 2048; // Winning tile value
// Initialize the game board
void init_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

// Print the game board
void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}
// Generate a new random tile on the board
void generate_tile(int board[ROWS][COLS]) {
    int i, j;
    do {
        i = rand() % ROWS;
        j = rand() % COLS;
    } while (board[i][j] != 0);
    board[i][j] = (rand() % 2 + 1) * 2; // New tile is either 2 or 4
}
// Shift the tiles in the specified direction (left, right, up, or down)
void shift_tiles(int board[ROWS][COLS], char direction) {
    bool moved = false;
    if (direction == 'L') { // Shift left
        for (int i = 0; i < ROWS; i++) {
            for (int j = 1; j < COLS; j++) {
                if (board[i][j] != 0) {
                    int k = j;
                    while (k > 0 && board[i][k-1] == 0) {
                        board[i][k-1] = board[i][k];
                        board[i][k] = 0;
                        k--;
                        moved = true;
                    }
                    if (k > 0 && board[i][k-1] == board[i][k]) {
                        board[i][k-1] *= 2;
                        board[i][k] = 0;
                        moved = true;
                    }
                }
            }
        }
    } else if (direction == 'R') { // Shift right
        for (int i = 0; i < ROWS; i++) {
            for (int j = COLS-2; j >= 0; j--) {
                if (board[i][j] != 0) {
                    int k = j;
                    while (k < COLS-1 && board[i][k+1] == 0) {
                        board[i][k+1] = board[i][k];
                        board[i][k] = 0;
                        k++;
                        moved = true;
                    }
                    if (k < COLS-1 && board[i][k+1] == board[i][k]) {
                        board[i][k+1] *= 2;
                        board[i][k] = 0;
                        moved = true;
                    }
                }
            }
        }
    } else if (direction == 'U') { // Shift up
        for (int j = 0; j < COLS; j++) {
            for (int i = 1; i < ROWS; i++) {
                if (board[i][j] != 0) {
                    int k = i;
                    while (k > 0 && board[k-1][j] == 0) {
                        board[k-1][j] = board[k][j];
                        board[k][j] = 0;
                        k--;
                        moved = true;
                    }
                    if (k > 0 && board[k-1][j] == board[k][j]) {
                        board[k-1][j] *= 2;
                        board[k][j] = 0;
                        moved = true;
                    }
                }
            }
        }
    } else if (direction == 'D') { // Shift down
        for (int j = 0; j < COLS; j++) {
            for (int i = ROWS-2; i >= 0; i--) {
                if (board[i][j] != 0) {
                    int k = i;
                    while (k < ROWS-1 && board[k+1][j] == 0) {
                        board[k+1][j] = board[k][j];
                        board[k][j] = 0;
                        k++;
                        moved = true;
                    }
                    if (k < ROWS-1 && board[k+1][j] == board[k][j]) {
                        board[k+1][j] *= 2;
                        board[k][j] = 0;
                        moved = true;
                    }
                }
            }
        }
    }
    if (moved) {
        generate_tile(board);
    }
}
int main() {
    srand(time(NULL)); // Seed the random number generator
    int board[ROWS][COLS];
    init_board(board);
    generate_tile(board);
    generate_tile(board);
    print_board(board);
    while (true) {
        char direction;
        cout << "Enter direction (L=left, R=right, U=up, D=down): ";
        cin >> direction;
        shift_tiles(board, direction);
        print_board(board);
        bool won = false;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == TARGET) {
                    won = true;
                }
            }
        }
        if (won) {
            cout << "Congratulations, you won!" << endl;
            break;
        }
    }
    return 0;
}

           
