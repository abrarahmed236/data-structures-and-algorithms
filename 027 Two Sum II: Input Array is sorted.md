# Two Sum II - Input Array Is Sorted (Problem 167)

Again simple straight forward solution with two pointer approach.

```cpp
class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end) {
            int sum = numbers[start] + numbers[end];
            if (sum < target)
                start++;
            else if (sum > target)
                end--;
            else
                break;
        }
        return {start + 1, end + 1};
    }
};
```