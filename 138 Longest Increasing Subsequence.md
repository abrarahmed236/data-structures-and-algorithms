# Longest Increaseing Subsequence (Problem 300)

Backtracking solution is possible too `//later`

1D DP solution

```cpp
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1);
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
```

Some equivalent of kadane's algorithm. `//revisit`
```cpp
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
            if (it == arr.end())
                arr.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return arr.size();
    }
};
```