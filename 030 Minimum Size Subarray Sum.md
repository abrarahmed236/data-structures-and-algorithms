# Minimum Size Subarray Sum (Problem 209)

n^3 sliding window solution (TLE)
```cpp
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();
        int window_size = 0;
        while (++window_size <= N) {
            for (int i = 0; i < (N - window_size + 1); i++) {
                int window_sum = 0;
                for (int j = i; j < i + window_size; j++) {
                    window_sum += nums[j];
                }
                if (window_sum >= target) {
                    return window_size;
                }
            }
        }
        return 0;
    }
};
```

n^2 sliding window solution, better sliding window (TLE)

```cpp
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();
        int window_size = 0;
        while (++window_size <= N) {
            int window_sum = 0;
            for (int i = 0; i < window_size; i++) {
                window_sum += nums[i];
            }
            if (window_sum >= target) {
                return window_size;
            }
            for (int i = window_size; i < N; i++) {
                window_sum += nums[i] - nums[i - window_size];
                if (window_sum >= target) {
                    return window_size;
                }
            }
        }
        return 0;
    }
};
```

Dynamic sliding window
```cpp
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();
        int min_size = INT_MAX;

        int window_sum = 0;

        int begin = 0;
        int one_over = 0;
        while (one_over < N) {
            window_sum += nums[one_over];
            while (window_sum >= target) {
                min_size = min(min_size, one_over - begin + 1);
                window_sum -= nums[begin];
                begin++;
            }
            one_over++;
        }

        return min_size == INT_MAX ? 0 : min_size;
    }
};
```