# Find Peak Element (Problem 162)

Simple Binary Search Approach. TO-DO: write explanation

```cpp
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[N - 2] < nums[N - 1]) return N - 1;

        int begin = 1, end = N - 2;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
                begin = mid + 1;
            else
                end = mid - 1;
        }

        return -1;
    }
};
```
