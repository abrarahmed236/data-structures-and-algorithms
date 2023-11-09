# Climbing Stairs (Problem 70)

1D dynamic programming

```cpp
class Solution {
   public:
    int climbStairs(int n) {
        if (n < 3) return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```

1D dynamic programming without tabulation

```cpp
class Solution {
   public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int dp1 = 1, dp2 = 2, dp3;
        for(int i=3; i<=n; i++) {
            dp3 = dp1 + dp2;
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp3;
    }
};
```
