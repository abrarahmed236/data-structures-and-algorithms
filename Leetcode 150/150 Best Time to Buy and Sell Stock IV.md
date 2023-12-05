# Best Time to Buy and Sell Stock IV (Problem 188)

- [ ] Revision Needed

2D dp,
[Refer](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/solutions/2555699/leetcode-the-hard-way-7-lines-line-by-line-explanation/?envType=study-plan-v2&envId=top-interview-150)
`//revisit`

Firstly we can attempt an O(N^2) solution while remembering the K most
profitable buy and sell dates.
```cpp
for(int i=0; i<N; i++) {
    max_j = arr[i];
    for(int j=i+1; j<N; j++) {
        max_j = max(max_j, arr[j]);
    }
    int profit = max_j - arr[i];
    // no but this doesn't take into account that we need to recurse again from j
    // since we cannot hold more than one stock at a time.
    // A 2D dp is the best solution for this problem it seems
}
```

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

### Another Code

```cpp
struct info {
    int buy;
    int sell;
};
class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) return 0;

        vector<info> dp(k + 1, {INT_MAX, 0});
        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                dp[i].buy = min(dp[i].buy, price - dp[i - 1].sell);
                dp[i].sell = max(dp[i].sell, price - dp[i].buy);
            }
        }

        return dp[k].sell;
    }
};
```
