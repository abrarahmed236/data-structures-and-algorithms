# [Edit Distance (Problem 72)](https://leetcode.com/problems/edit-distance/description/?envType=study-plan-v2&envId=top-interview-150)

2D dp `//revisit`

```cpp
class Solution {
   public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 1; i <= M; i++) dp[i][0] = i;
        for (int j = 1; j <= N; j++) dp[0][j] = j;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] =
                        min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) +
                        1;
            }
        }
        return dp[M][N];
    }
};
```

```mermaid
graph TD
  A[ ] -- 0 -->|0| B[ ] 
  A -- 1 -->|1| C[ ] 
  A -- 2 -->|2| D[ ] 
  A -- 3 -->|3| E[ ] 
  B -- 0 -->|1| F[1]
  C -- 1 -->|1| G[1]
  C -- 2 -->|2| H[ ]
  D -- 1 -->|1| I[1]
  D -- 2 -->|2| J[ ]
  D -- 3 -->|3| K[1]
```

|   | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| 0 | 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 | 0 |
| 2 | 0 | 1 | 0 | 0 |
| 3 | 0 | 1 | 1 | 1 |

|   | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| 0 | 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 | 0 |
| 2 | 0 | 1 | 0 | 0 |
| 3 | 0 | 1 | 1 | 1 |


+---+---+---+---+
|   | 0 | 1 | 2 | 3 |
+---+---+---+---+
| 0 | 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 | 0 |
| 2 | 0 | 1 | 0 | 0 |
| 3 | 0 | 1 | 1 | 1 |
+---+---+---+---+


can also make this O(N) space
