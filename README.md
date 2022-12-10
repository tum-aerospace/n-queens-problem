# N Queens Problem

The n queens problem is the problem of placing n chess queens on an nxn chessboard so that no two queens are able two attack each other
(i.e. no two are in the same row, column or diagonal).

There are multiple ways to generate a valid solution:

## Algorithms

### Backtracking

For the "backtracking" approach we place a queen in the top left (first row, first column), then place the second queen in the second row
and move it until this queen is at a location where it cannot be hit by the queen in the first row. Then we place a queen in the third
row and move it until it cannot be hit by either of the first two queens. This process is continued with the remaining rows.
If there is no place for a queen in the current row we go back to the preceding row and move the queen in that row. If the queen there
is already at the end of its row, we remove that queen and go back to the preceding row, where we move the queen and work our way down again.
If the current row is the last row and a safe place has been found for the last queen, the a solution to the problem has been found.
If the current row is the first row and its queen is being moved off the board, then all possible configurations have been examined
and no valid solution exists for the value of n.

## Usage

You can build this project with [CMake](https://cmake.org/).

The program has one optional command line argument where you can specify the value of `n`, which defaults to 8 if you leave the
argument away.

To generate a solution for `n = 4`:
```
nqueensproblem 4
```
