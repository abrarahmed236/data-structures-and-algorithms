# Coin Change (Problem 322)

Quick and Dirty

```cpp
class Solution {
   public:
    int util(int amount, const vector<int>& coins,
             unordered_map<int, int>& dp) {
        if (dp.count(amount)) return dp[amount];
        int result = INT_MAX;
        if (amount < 0) return dp[amount] = result;
        for (auto c : coins) {
            int temp = util(amount - c, coins, dp);
            if (temp == INT_MAX)
                continue;
            else
                result = min(result, 1 + temp);
        }
        return dp[amount] = result;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        if (coins.size() == 0) return -1;
        if (coins.size() == 1)
            return amount % coins[0] == 0 ? amount / coins[0] : -1;
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (auto n : coins) dp[n] = 1;
        int result = util(amount, coins, dp);
        return result == INT_MAX ? -1 : result;
    }
};
```

Can be massively improved by making the dp in a bottom up fashion instead of
recursively. And by using arrays, instead of stl containers. Bottom up DP should
be preferred whenever possible for ease of use and cleaner code.

```cpp
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        dp[0] = 0;
        sort(coins.begin(), coins.end());

        for (int i = 1; i <= amount; i++) {
            dp[i] = INT_MAX;
            for (int c : coins) {
                if (i - c < 0) break;
                if (dp[i - c] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
```

While top down versions do not perform as well for dense DP arrays, they will
perform well for sparse DP. There is some scope of using unordered_maps too, if
the amount is very large and the search is going to be sparse. But it should be
noted that unordered_maps in general are ~10x-20x slower than arrays.

```cpp
class Solution {
   public:
    int util(int amount, vector<int>& coins, int dp[]) {
        if (dp[amount] != INT_MAX) return dp[amount];

        dp[amount] = INT_MAX - 1;
        for (auto c : coins) {
            if (amount - c < 0) break;
            dp[amount] = min(dp[amount], 1 + util(amount - c, coins, dp));
        }

        return dp[amount] == INT_MAX ? INT_MAX - 1 : dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // Coins Preprocessing
        sort(coins.begin(), coins.end());
        if (coins.size() == 0) return -1;
        if (coins.size() == 1)
            return amount % coins[0] == 0 ? amount / coins[0] : -1;

        // DP Preprocessing
        int dp[amount + 1];
        for (int& i : dp) i = INT_MAX;
        dp[0] = 0;
        for (auto n : coins)
            if (n < amount) dp[n] = 1;

        // Get Result
        int result = util(amount, coins, dp);
        return result >= INT_MAX - 1 ? -1 : result;
    }
};
```
