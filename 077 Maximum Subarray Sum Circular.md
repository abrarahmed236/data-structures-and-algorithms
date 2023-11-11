# Maximum Sum Circular Subarray (Problem 918)

Particularly badly performing code. O(N^2)

```cpp
class Solution {
    bool same_sign(int a, int b) {
        return (a < 0 && b < 0) || (a >= 0 && b >= 0);
    }

   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sofar = 0;
        int max_sum = *max_element(nums.begin(), nums.end());
        vector<int> compressed;
        compressed.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (same_sign(compressed.back(), nums[i])) {
                compressed.back() += nums[i];
            } else {
                compressed.push_back(nums[i]);
            }
        }
        nums = compressed;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            if (nums[i] > 0) {
                max_sofar = 0;
                for (int j = 0; j < N; j++) {
                    int curr = nums[(i + j) % N];
                    max_sofar = max(max_sofar + curr, curr);
                    max_sum = max(max_sum, max_sofar);
                }
                while (i + 1 < N && nums[i + 1] > 0) i++;
            }
        }
        return max_sum;
    }
};
```

Modified Kadane's algorithm.  
Two possible cases in this problem:

- max sum does not go over the edges of the vector
  - in this case standard kadane's algorithm is perfectly suited.
- max sum goes over the edges of the vector
  - in this case we find the min_sum, which is the largest contiguous negative
    sum subarray and then subtract that from the total

```cpp
class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int max_sofar = 0;
        int max_sum = nums[0];
        int min_sofar = 0;
        int min_sum = nums[0];

        for (int num : nums) {
            total += num;

            max_sofar = max(max_sofar + num, num);
            max_sum = max(max_sum, max_sofar);

            min_sofar = min(min_sofar + num, num);
            min_sum = min(min_sum, min_sofar);
        }

        return total == min_sum ? max_sum : max(total - min_sum, max_sum);
    }
};
```
