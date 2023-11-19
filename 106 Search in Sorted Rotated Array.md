# Search in Sorted Rotated Array (Problem 33)

Find the pivot using binary search.  
Find the element using the pivot and binary search.

```cpp
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        int offset;
        int N = nums.size();
        if (nums.front() < nums.back())
            offset = 0;
        else {
            int begin = 0, end = N - 1;
            while (begin <= end) {
                int mid = (begin + end) / 2;
                if (mid > 0 && nums[mid - 1] > nums[mid]) {
                    offset = mid;
                    break;
                } else if (nums[0] > nums[mid]) {
                    end = mid - 1;
                } else
                    begin = mid + 1;
            }
        }

        int begin = 0, end = N - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            int mod = (mid + offset) % N;
            if (nums[mod] == target)
                return mod;
            else if (nums[mod] < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }

        return -1;
    }
};
```

Can do this in a single binary search.

```cpp
// later
```
