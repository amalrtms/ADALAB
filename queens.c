#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4
int board[N];
int solutionCount = 0;
int isSafe(int row, int col) {
    for (int prev = 0; prev < row; prev++) {
        if (board[prev] == col||abs(board[prev] - col) == abs(prev - row)) {
            return 0;
        }
    }
    return 1;
}
void print_solution() {
    solutionCount++;
    printf("Solution %d:\n", solutionCount);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}
void solve(int row) {
    if (row == N) {
        print_solution();
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}
int main() {
    solve(0);
    printf("Total solutions: %d\n", solutionCount);
    return 0;
}
