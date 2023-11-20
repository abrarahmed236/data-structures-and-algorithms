# Game of Life (Problem 289)

```cpp
class Solution {
   public:
    void gameOfLife(vector<vector<int>>& board) {
        int i_max = board.size();
        int j_max = board[0].size();

        for (int i = 0; i < i_max; i++) {
            for (int j = 0; j < j_max; j++) {
                int buddies = 0;

                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) continue;
                        if (i + x >= 0 && j + y >= 0 && i + x < i_max &&
                            j + y < j_max && board[i + x][j + y] & 1)
                            buddies++;
                    }
                }

                if ((board[i][j] & 1 && (buddies == 2 || buddies == 3)) ||
                    (!(board[i][j] & 1) && buddies == 3))
                    board[i][j] |= 2;
            }
        }

        for (int i = 0; i < i_max; i++) {
            for (int j = 0; j < j_max; j++) {
                board[i][j] = board[i][j] & 2 ? 1 : 0;
            }
        }
    }
};
```
