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

Can be massively improved.
