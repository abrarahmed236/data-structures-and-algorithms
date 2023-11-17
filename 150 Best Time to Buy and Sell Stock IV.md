# Best Time to Buy and Sell Stock IV (Problem 188)

2D dp,
[Refer](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/solutions/2555699/leetcode-the-hard-way-7-lines-line-by-line-explanation/?envType=study-plan-v2&envId=top-interview-150) `//revisit`

```cpp
class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) return 0;

        vector<vector<int>> dp(k + 1, vector<int>(2));
        for (int i = 0; i <= k; i++) dp[i][0] = INT_MAX;
        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                dp[i][0] = min(dp[i][0], price - dp[i - 1][1]);
                dp[i][1] = max(dp[i][1], price - dp[i][0]);
            }
        }

        return dp[k][1];
    }
};
```
