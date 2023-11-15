# Find First and Last Position of Element in Sorted Array (Problem 34)

Use binary search twice,  
once to find the first element  
once to find the last element

```cpp
class Solution {
    int binary_first(vector<int>& A, int target) {
        int N = A.size();
        int beg = 0;
        int end = N - 1;
        while (beg <= end) {
            int mid = (beg + end) >> 1;
            if (A[mid] == target && (mid == 0 || A[mid - 1] != target))
                return mid;
            else if (A[mid] < target)
                beg = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
    int binary_last(vector<int>& A, int target) {
        int N = A.size();
        int beg = 0;
        int end = N - 1;
        while (beg <= end) {
            int mid = (beg + end) >> 1;
            if (A[mid] == target && (mid == N - 1 || A[mid + 1] != target))
                return mid;
            else if (A[mid] <= target)
                beg = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid_1 = binary_first(nums, target);
        int mid_2 = binary_last(nums, target);

        return {mid_1, mid_2};
    }
};
```

cleaner code using lower_bound and upper_bound from STL  
Need to look carefully at edge cases, but otherwise good.

```cpp
class Solution {
   public:
    vector<int> searchRange(vector<int>& A, int target) {
        int low = lower_bound(A.begin(), A.end(), target) - A.begin();
        int up = upper_bound(A.begin(), A.end(), target) - A.begin() - 1;
        if (low != A.size() && low <= up) return {low, up};
        return {-1, -1};
    }
};
```
