#include<iostream>
#include<vector>
using namespace std;
    bool isSafe(vector<vector<char>>& board, int row, int col, char digit) {
        for (int i = 0; i <= 8; i++) {
            if (board[i][col] == digit) {
                return false;
            }
        }
        // horizontal
        for (int j = 0; j <= 8; j++) {
            if (board[row][j] == digit) {
                return false;
            }
        }
        // grid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i <= startRow + 2; i++) {
            for (int j = startCol; j <= startCol + 2; j++) {
                if (board[i][j] == digit) {
                    return false;
                }
            }
        }
        return true;
    }

    bool sudokuSolver(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true;
        }
        int nextRow = row;
        int nextCol = col;
        if (col + 1 == 9) {
            nextRow = row + 1;
            nextCol = 0;
        } else {
            nextCol = col + 1;
        }
        if (board[row][col] != '.') {
            return sudokuSolver(board, nextRow, nextCol);
        }
        for (char digit = '1'; digit <= '9'; digit++) {
            if (isSafe(board, row, col, digit)) {
                board[row][col] = digit;
                if (sudokuSolver(board, nextRow, nextCol)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    int main() {

    return 0;
}
