# House Robber (Problem 198)

Iterate over the array.  
You can either include current house + previous but one houses.  
Or you can exclude current house and include previous house.

DP implementation of the Above. Not 100% sure but it works.

```cpp
class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums);
        dp.push_back(0);
        for (int i = dp.size() - 3; i >= 0; i--) {
            dp[i] = max(dp[i + 1], dp[i + 2] + dp[i]);
        }

        return dp[0];
    }
};
```

Better DP solution, since this problem looks very similar to fibbonacci problem.
```cpp
class Solution {
   public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        int dp0 = 0;
        int dp1 = nums[0];
        int dp2 = dp1;
        for (int i = 1; i < N; i++) {
            dp2 = max(dp0 + nums[i], dp1);
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp2;
    }
};
```