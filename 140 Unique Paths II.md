# Unique Paths II (Problem 63)

2D DP

```cpp
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>> dp(M, vector<int>(N));

        if (grid[0][0]) return 0;
        dp[0][0] = grid[0][0] ? 0 : 1;
        for (int i = 1; i < M; i++) dp[i][0] = grid[i][0] ? 0 : dp[i - 1][0];
        for (int j = 1; j < N; j++) dp[0][j] = grid[0][j] ? 0 : dp[0][j - 1];
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                dp[i][j] = grid[i][j] ? 0 : (dp[i - 1][j] + dp[i][j - 1]);
            }
        }
        return dp[M - 1][N - 1];
    }
};
```

2D DP, recursive with pruning. `//revisit`

```cpp
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int M = obs.size();
        int N = obs[0].size();
        vector<vector<int>> dp(M, vector<int>(N, -1));
        return recurse(0, 0, obs, dp);
    }
    int recurse(int i, int j, vector<vector<int>>& obs,
                vector<vector<int>>& dp) {
        if (i >= obs.size() || j >= obs[0].size()) return 0;

        if (obs[i][j] == 1) return 0;

        if (i == obs.size() - 1 && j == obs[0].size() - 1) return 1;

        if (dp[i][j] == -1)
            dp[i][j] = recurse(i + 1, j, obs, dp) + recurse(i, j + 1, obs, dp);
        return dp[i][j];
    }
};
```
