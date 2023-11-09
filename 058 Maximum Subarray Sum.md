# Maximum Subarray Sum (Problem 53)

Brute force (TLE)

```cpp
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (maxSum < sum) maxSum = sum;
            }
        }
        return maxSum;
    }
};
```

Kadane's Algorithm

```cpp
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int max_sofar = 0;
        int max_sum = INT_MIN;
        int max_elem = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            max_sofar = max(max_sofar + nums[i], 0);
            max_sum = max(max_sum, max_sofar);
            max_elem = max(max_elem, nums[i]);
        }

        return max_sum == 0 ? max_elem : max_sum;
    }
};
```

Kadane's Algorith for Negative Numbers

```cpp
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int max_sofar = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            max_sofar = max(max_sofar + nums[i], nums[i]);
            max_sum = max(max_sum, max_sofar);
        }

        return max_sum;
    }
};
```
