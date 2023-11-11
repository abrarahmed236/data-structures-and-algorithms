# Surrounded Regions (Problem 130)

DFS from the boundary. Anything not touched by this DFS can be flipped.

```cpp
class Solution {
    int M, N;
    void DFS(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= M || j >= N || board[i][j] != 'O') return;
        board[i][j] = '#';
        DFS(board, i - 1, j);
        DFS(board, i + 1, j);
        DFS(board, i, j - 1);
        DFS(board, i, j + 1);
    }

   public:
    void solve(vector<vector<char>>& board) {
        M = board.size();
        N = board[0].size();

        // first and last row
        for (int j = 0; j < N; j++) {
            if (board[0][j] == 'O') DFS(board, 0, j);
            if (board[M - 1][j] == 'O') DFS(board, M-1, j);
        }
        // first and last column
        for (int i = 0; i < M; i++) {
            if (board[i][0] == 'O') DFS(board, i, 0);
            if (board[i][N - 1] == 'O') DFS(board, i, N-1);
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
```
