# Search Insert Position (Problem 35)

Straight forward binary search

```cpp
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = (begin + end) / 2;

        while (begin <= end) {
            mid = (begin + end) / 2;
            if (nums[mid] < target)
                begin = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                return mid;
        }

        return begin;
    }
};
```