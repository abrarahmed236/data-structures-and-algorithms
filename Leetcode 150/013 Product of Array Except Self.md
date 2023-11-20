# [Product of Array Except Self (Problem 238)](https://leetcode.com/problems/product-of-array-except-self/)

```cpp
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefix(N, 1);
        vector<int> suffix(N, 1);

        for (int i = 1; i < N; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for (int i = N - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};
```

```cpp
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> result;
        result.resize(N);

        int prefix = 1;
        for (int i = 0; i < N; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for (int i = N - 1; i >= 0; i--) {
            result[i] *= postfix;
            postfix *= nums[i];
        }

        return result;
    }
};
```
