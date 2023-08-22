# [Best time to Buy and Sell Stock (Problem 121)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

## Description

You are given an array `prices` where `prices[i]` is the price of a given  
stock on the `i-th` day.

You want to maximize your profit by choosing a **single day** to buy one stock  
and choosing a **different day in the future** to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot  
achieve any profit, return `0`.

### Example 1:

> **Input**: prices = `[7,1,5,3,6,4]`  
> **Output**: `5`  
> **Explanation**: Buy on day 2 (price = `1`) and sell on day 5 (price = `6`),  
> profit = `6-1` = `5`. Note that buying on day 2 and selling on day 1 is not  
> allowed because you must buy before you sell.

### Example 2:

> **Input**: prices = [7,6,4,3,1]  
> **Output**: 0  
> **Explanation**: In this case, no transactions are done and the max profit
> = 0.

### Constraints:

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

## Approach 1

A brute force approach to this problem would be to calculate the profit for  
each pair of buying dates and selling dates, and then choosing the maximum  
profit.

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for(int i=0; i<prices.size()-1; i++) {
            for(int j=i+1; j<prices.size(); j++) {
                maxProfit = max(maxProfit, prices[j]-prices[i]);
            }
        }
        return maxProfit;
    }
};
```

### Complexity

- **Time**: `O(N^2)`
- **Space**: `O(1)`

### Discussion

The problem with this approach is that it does not take into account the  
nature of the problem and simply calculates every possible solution. We can do  
better than this.

## Approach 2

Since the problem has a linear structure in time, we can try to remember the  
best price (lowest) we have encountered so far and the best profit (highest)  
we have encountered so far. And finally return the best profit at the end.

If we encounter a better initial price, then we still need to encounter a  
better profit in the future to be able to use it. And if we had encountered a  
better profit on a worse initial price earlier we will still remember the  
better profit from before.

This line `bestProfit = max(bestProfit, prices[i]-bestPrice)` takes care of  
both these scenarios.

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int bestPrice = prices[0];
        int bestProfit = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]<bestPrice) {
                bestPrice = prices[i];
            } else {
                bestProfit = max(bestProfit, prices[i]-bestPrice);
            }
        }
        return bestProfit;
    }
};
```

### Complexity:

- **Time**: `O(N)`
- **Space**: `O(1)`
