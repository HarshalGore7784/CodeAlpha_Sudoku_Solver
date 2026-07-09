#include <iostream>

using namespace std;

#define N 9

void printGrid(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        if (r % 3 == 0 && r != 0) cout << "---------------------\n";
        for (int c = 0; c < N; c++) {
            if (c % 3 == 0 && c != 0) cout << "| ";
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return false;
}

bool solveSudoku(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N) return true;
    if (col == N) {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0) return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

int main() {
    cout << "===============================\n";
    cout << "   CODEALPHA SUDOKU SOLVER     \n";
    cout << "===============================\n\n";

    // Sample puzzle (0 represent empty cells)
    int grid[N][N] = {
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

    cout << "Original Puzzle Grid:\n";
    printGrid(grid);
    cout << "\nSolving...\n\n";

    if (solveSudoku(grid, 0, 0)) {
        cout << "Puzzle Solved Successfully:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the given puzzle.\n";
    }
    return 0;
}