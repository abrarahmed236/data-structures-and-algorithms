# Minimum Path Sum (Problem 64)

Classic 2D DP problem  
Update first row and column in a prefix sum manner.  
For the rest of the elements update the minimum of element above and element to
the left.

```cpp
class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        // update first row and column
        for (int j = 1; j < N; j++) grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < M; i++) grid[i][0] += grid[i - 1][0];

        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[M - 1][N - 1];
    }
};
```
