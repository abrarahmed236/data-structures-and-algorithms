# Maximal Square (Problem 221)

Straight forward 2D dp

```cpp
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int>> dp(M, vector<int>(N));

        int result = 0;
        auto update_result = [&result, &dp](int i, int j) {
            if (dp[i][j] > result) result = dp[i][j];
        };
        // Initialize first row and column of DP
        for (int j = 0; j < N; j++) {
            dp[0][j] = matrix[0][j] - '0';
            update_result(0, j);
        }
        for (int i = 0; i < M; i++) {
            dp[i][0] = matrix[i][0] - '0';
            update_result(i, 0);
        }

        // Iterate over the rest of the elements
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] =
                        min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) +
                        1;
                    update_result(i, j);
                }
            }
        }

        // return the last element
        return result * result;
    }
};
```

1D dp with two vectors

```cpp
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<int> prev(N);
        vector<int> curr(N);

        int result = 0;
        // Initialize the first row as prev
        for (int j = 0; j < N; j++) {
            prev[j] = matrix[0][j] - '0';
            if (prev[j] > result) result = prev[j];
        }

        // Iterate over the rest of the elements
        for (int i = 1; i < M; i++) {
            curr[0] = matrix[i][0] - '0';
            if (curr[0] > result) result = curr[0];
            for (int j = 1; j < N; j++) {
                curr[j] = matrix[i][j] == '1' ? 1 : 0;
                curr[j] = curr[j]
                              ? min(curr[j - 1], min(prev[j], prev[j - 1])) + 1
                              : 0;
                if (curr[j] > result) result = curr[j];
            }
            swap(prev, curr);
        }

        // return the last element
        return result * result;
    }
};
```

1D dp with only one vector

```cpp
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size(), N = matrix[0].size(), result = 0, prev;
        int curr[N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int temp = curr[j];
                if (!i || !j || matrix[i][j] == '0') {
                    curr[j] = matrix[i][j] - '0';
                } else {
                    curr[j] = min(prev, min(curr[j], curr[j - 1])) + 1;
                }
                result = max(curr[j], result);
                prev = temp;
            }
        }
        return result * result;
    }
};
```
