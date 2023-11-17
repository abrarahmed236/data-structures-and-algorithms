# N Queens II (Problem 52)

Recursive Backtracking `//revisit`

```cpp
class Solution {
    typedef int Elem;
    typedef vector<vector<Elem>> Board;
    typedef vector<Elem> Row;

   public:
    int totalNQueens(int n) {
        Board board(n, Row(n));
        int result = 0;
        solve(board, 0, result);
        return result;
    }
    void solve(Board& board, int row, int& result) {
        if (row == board.size()) {
            result++;
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            if (check(board, row, col)) {
                board[row][col] = 1;
                solve(board, row + 1, result);
                board[row][col] = 0;
            }
        }
    }
    bool check(Board& board, int row, int col) {
        int N = board.size();
        for (int i = 0; i <= row; i++) {
            if (board[i][col]) return false;
            // checking diagonals
            if (row - i >= 0 && col - i >= 0 && board[row - i][col - i])
                return false;
            if (row - i >= 0 && col + i < N && board[row - i][col + i])
                return false;
        }
        return true;
    }
};
```

Since we do not need to return the board, we do not need to simulate it at all.
Instead, we can remember which columns, diagonals and anti_diagonals are already
occupied. Here the challenge is the indexing of the anti_diagonals. `//revisit`

```cpp
class Solution {
    typedef vector<int> Mem;

   public:
    int totalNQueens(int n) {
        Mem col(n), diag(2 * n - 1), anti_diag(2 * n - 1);
        int result = 0;
        solve(0, col, diag, anti_diag, result, n);
        return result;
    }
    void solve(int row, Mem& col, Mem& diag, Mem& anti_diag, int& result,
               int N) {
        if (row == N) {
            result++;
            return;
        }
        for (int i = 0; i < N; i++) {
            int anti_i = row - i + N - 1;
            if (!col[i] && !diag[row + i] && !anti_diag[anti_i]) {
                col[i] = diag[row + i] = anti_diag[anti_i] = 1;
                solve(row + 1, col, diag, anti_diag, result, N);
                col[i] = diag[row + i] = anti_diag[anti_i] = 0;
            }
        }
    }
};
```
