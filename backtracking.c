#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_solution(int n, bool board[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                printf("Q");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool is_safe(int n, bool board[n][n], int row, int col) {
    int i, j;

    // check column above row
    for (i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // check upper diagonal on right side
    for (i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool place_queens(int n, bool board[n][n], int row) {
    if (row >= n) {
        return true;
    }

    for (int j = 0; j < n; j++) {
        if (is_safe(n, board, row, j)) {
            board[row][j] = true;

            if (place_queens(n, board, row + 1)) {
                return true;
            }

            board[row][j] = false;
        }
    }

    return false;
}

int main(int argc, char* argv[]) {
    int n;
    if (argc == 1) {
        n = 8;
    } else if (argc == 2) {
        n = atoi(argv[1]);
    } else {
        puts("wrong number of arguments");
        return -1;
    }

    if (n <= 0) {
        printf("invalid argument for n: %s\n", argv[1]);
        return -1;
    }

    bool board[n][n];
    memset(board, false, sizeof(board));

    if (place_queens(n, board, 0) == false) {
        puts("no solution found");
    } else {
        print_solution(n, board);
    }

    return 0;
}
