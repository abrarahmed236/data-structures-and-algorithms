# Triangle (Problem 120)

Simple 2D dynamic programming

```cpp
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        for (int i = 1; i < dp.size(); i++) {
            dp[i][0] += dp[i - 1][0];
            for (int j = 1; j < i; j++) {
                dp[i][j] += min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
            dp[i][i] += dp[i - 1][i - 1];
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
```

Same as above but inplace

```cpp
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            triangle[i][0] += triangle[i - 1][0];
            for (int j = 1; j < i; j++) {
                triangle[i][j] +=
                    min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
            triangle[i][i] += triangle[i - 1][i - 1];
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};
```

Doing this with only O(n) space

```cpp
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp, dp1;
        dp.reserve(triangle.size());
        dp1.reserve(triangle.size());
        dp.push_back(triangle[0][0]);
        for (int i = 1; i < triangle.size(); i++) {
            dp1.push_back(dp[0] + triangle[i][0]);
            for (int j = 1; j < i; j++) {
                dp1.push_back(triangle[i][j] + min(dp[j - 1], dp[j]));
            }
            dp1.push_back(dp[i - 1] + triangle[i][i]);
            swap(dp1, dp);
            dp1.clear();
        }
        return *min_element(dp.begin(), dp.end());
    }
};
```

All of the above have a problem. They are building the solution from the top of
the triangle. This problem is easier if you deal with it from the bottom of the
triangle.

2D DP, bottom up

```cpp
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        for (int i = dp.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++)
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j];
        }

        return dp[0][0];
    }
};
```

Inplace, bottom up

```cpp
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++)
                triangle[i][j] =
                    min(triangle[i + 1][j], triangle[i + 1][j + 1]) +
                    triangle[i][j];
        }

        return triangle[0][0];
    }
};
```

O(N) space, bottom up

```cpp
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle.back();

        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        }

        return dp[0];
    }
};
```
