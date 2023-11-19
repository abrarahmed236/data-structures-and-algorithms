# [Best Time to Buy and Sell Stock II (Problem 122)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

## Description

You are given an integer array `prices` where `prices[i]` is the price of a
given stock on the `i-th` day.

On each day, you may decide to buy and/or sell the stock. You can only hold **at
most one** share of stock at any time. However, you can buy it and then
immediately sell it on the same day.

Find and return the **maximum** profit you can achieve.

### Example 1

> **Input**: prices = [7,1,5,3,6,4]  
> **Output**: 7  
> **Explanation**: Buy on day 2 (price = 1) and sell on day 3 (price = 5),
> profit = 5-1 = 4.  
> Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3
> = 3.  
> Total profit is 4 + 3 = 7.

### Example 2

> **Input**: prices = [1,2,3,4,5]  
> **Output**: 4  
> **Explanation**: Buy on day 1 (price = 1) and sell on day 5 (price = 5),
> profit = 5-1 = 4.  
> Total profit is 4.

### Example 3

> **Input**: prices = [7,6,4,3,1]  
> **Output**: 0  
> **Explanation**: There is no way to make a positive profit, so we never buy
> the stock to achieve the maximum profit of 0.

### Constraints

- `1 <= prices.length <= 3 * 10^4`
- `0 <= prices[i] <= 10^4`

## Approach 1

Since we are not constrained with buying and selling only once, we can simple
buy and sell for each instance where we get a profit.

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int total_profit = 0;
        for(int i=1, profit; i<N; i++) {
            profit = prices[i]-prices[i-1];
            if(profit > 0) total_profit += profit;
        }
        return total_profit;
    }
};
```

### Complexity

- **Time**: `O(N)`
- **Space**: `O(1)`

### Another Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* Discussion
            For the testcase given we can see the profit if you bought yesterday
        and sold today.
        Prices:  7  1  5  3  6  4
        Profits: 0 -6  4 -2  3 -2
            We can ignore the days when we get negative profits, and simply do
        this on days we get positive profit. i.e in the example above, it is
        day 3 and day 5. i.e buy on day 2 sell on day 3, buy on day 4 sell on day 5.
        This should accumulate the maximum profit.

        // Testcases
        -> 0 // empty input
        1 -> 0 // single day
        1 1 -> 0
        1 2 -> 1
        2 1 -> 0
        1 2 3 -> 2
        1 3 2 -> 2
        2 1 3 -> 2
        2 3 1 -> 1
        3 1 2 -> 1
        3 2 1 -> 0
        */
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            profit += max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
};
```
