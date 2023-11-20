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

|    | '' | e | x | e | c | u | t | i | o | n |
|--- |--- |---|---|---|---|---|---|---|---|---|
| '' | 0  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| i  | 1  | 1 | 2 | 3 | 4 | 5 | 6 | 6 | 7 | 8 |
| n  | 2  | 2 | 2 | 3 | 4 | 5 | 6 | 7 | 7 | 7 |
| t  | 3  | 3 | 3 | 3 | 4 | 5 | 5 | 6 | 7 | 8 |
| e  | 4  | 3 | 4 | 3 | 4 | 5 | 6 | 6 | 7 | 8 |
| n  | 5  | 4 | 4 | 4 | 4 | 5 | 6 | 7 | 7 | 7 |
| t  | 6  | 5 | 5 | 5 | 5 | 5 | 5 | 6 | 7 | 8 |
| i  | 7  | 6 | 6 | 6 | 6 | 6 | 6 | 5 | 6 | 7 |
| o  | 8  | 7 | 7 | 7 | 7 | 7 | 7 | 6 | 5 | 6 |
| n  | 9  | 8 | 8 | 8 | 8 | 8 | 8 | 7 | 6 | 5 |


can also make this O(N) space
