#include <stdio.h>
#include <stdlib.h>
#define N 8  // Change this to try different board sizes

int board[N][N];

// Check if placing a queen at board[row][col] is safe
int isSafe(int row, int col) {
    int i, j;

    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return 0;

    return 1;
}

// Solve N-Queens using backtracking
int solveNQueens(int row) {
    if (row >= N)
        return 1; // Found a solution

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1; // Place queen

            if (solveNQueens(row + 1))
                return 1; // Stop after finding one solution

            board[row][col] = 0; // Backtrack
        }
    }
    return 0; // No valid position in this row
}

// Print the chessboard
void printBoard() {
    printf("One valid N-Queens solution:\n\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
}

int main() {
    if (solveNQueens(0))
        printBoard();
    else
        printf("No solution exists for N = %d\n", N);

    return 0;
}
