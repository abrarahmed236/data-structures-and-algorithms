# Best Time to Buy and Sell Stock (Problem 123)

2D dp `//revisit`

```cpp
void pv(vector<int>& v) {
    for (auto& n : v) {
        cout << n << " ";
    }
    cout << endl;
}
void pvv(vector<vector<int>>& V) {
    for (auto& v : V) {
        pv(v);
    }
    cout << endl;
}

class Solution {
    static const int debug = false;

   public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if (N == 0) return 0;

        vector<vector<int>> dp(3, vector<int>(N));
        vector<int> mins(3, prices[0]);
        if (debug) pv(mins);

        for (int i = 1; i < N; i++) {
            for (int k = 1; k < 3; k++) {
                mins[k] = min(mins[k], prices[i] - dp[k - 1][i - 1]);
                dp[k][i] = max(dp[k][i - 1], prices[i] - mins[k]);
                if (debug) pvv(dp);
            }
        }

        return dp[2][N - 1];
    }
};
```

Minimal solution. `//revisit`

```cpp
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int sel1 = 0, sel2 = 0;

        for(int price: prices) {
            buy1 = min(buy1, price);
            sel1 = max(sel1, price - buy1);
            buy2 = min(buy2, price - sel1);
            sel2 = max(sel2, price - buy2);
        }

        return sel2;
    }
};
```
