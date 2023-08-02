# [Merge Sorted Array (Problem 88)](https://leetcode.com/problems/merge-sorted-array/)

## Description

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing  
order, and two integers `m` and `n`, representing the number of elements in  
`nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in **non-decreasing
order**.

The final sorted array should not be returned by the function, but instead be  
stored inside the array `nums1`. To accomodate this, `nums1` has a length of  
`m + n`, where the first `m` elements denote the elements that should be merged,  
and the last `n` elements are set to `0` and should be ignored. `nums2` has a  
length of `n`.

## Examples

### Example 1

> **Input:** nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3  
> **Output:** [1,2,2,3,5,6]  
> **Explanation:** The arrays we are merging are [1,2,3] and [2,5,6].  
> The result of the merge is [1,2,2,3,5,6].

### Example 2

> **Input:** nums1 = [1], m = 1, nums2 = [], n = 0  
> **Output:** [1]  
> **Explanation:** The arrays we are merging are [1] and [].  
> The result of the merge is [1].

### Example 3

> **Input**: nums1 = [0], m = 0, nums2 = [1], n = 1  
> **Output**: [1]  
> **Explanation**: The arrays we are merging are [] and [1].  
> The result of the merge is [1].  
> Note that because m = 0, there are no elements in nums1. The 0 is only there  
> to ensure the merge result can fit in nums1.

## Constraints

- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m,n <= 200`
- `1 <= m + n <= 200`
- `-10^9 <= nums1[i], nums2[j] <= 10^9`o

> **Follow Up:** Can you come up with an algorithm that runs in `O(m + n)` time
> ?

## Approach 1 - Copy and sort using STL

### Approach

A simple solution to this problem would be to copy over all the elements from  
`nums2` in the empty space in `nums1`. This step would take us O(n) time. And  
then we can use the standard library `sort` function to easily sort the array.  
This step would take us `O((m+n)log(m+n))` time. And we would not use any  
additional space, so our space complexity would be `O(1)`.

```text
-> [1, 2, 3, 0, 0, 0] , [2, 5, 6]
-> # Copy elements over to nums1
-> [1, 2, 3, 2, 5, 6]
-> # Now simply sort nums1 using std::sort
-> [1, 2, 2, 3, 5, 6]
```

### Complexity

- Time: `O((m+n)log(m+n))`
- Space: `O(1)`

### Code

```cpp
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Copy over the second array int the empty space in the first array
        for (int i = m, j = 0; j < n; i++, j++) {
            nums1[i] = nums2[j];
        }
        // Sort using STL
        std::sort(nums1.begin(), nums1.end());
    }
};
```

## Approach 2 - Two Pointer Approach

### Approach

In the above approach we aren't using the fact that the unmerged arrays are  
already sorted. We can find the greatest element in both arrays simply by  
looking at last element of both arrays.

```text
            i                    j
-> [1, 2, 5, 0, 0, 0] , [2, 3, 6]
    # Greatest element is the greater element among 5 or 6
```

We can then place the greater element at the end of `nums1` since we know that  
location is empty.

```text
            i        e           j
-> [1, 2, 5, 0, 0, 6] , [2, 3, 6]
```

We can then ignore the element that was the greatest in the previous step. Here  
we are marking it as `x`, in the code we can just ignore that element.

```text
            i        e           j
-> [1, 2, 5, 0, 0, 6] , [2, 3, x]
# And update the indices
            i     e           j
-> [1, 2, 5, 0, 0, 6] , [2, 3, x]
```

In the next iteration we see that `5` is greater than `3`, and we need to put 5  
in its correct place.

```text
        i     e              j
-> [1, 2, x, 0, 5, 6] , [2, 3, x]
```

Continuing on, we know our algorithm needs to stop when there are no more  
numbers left in the second array.

```text
# 3 is greater than 2
        i  e              j
-> [1, 2, x, 3, 5, 6] , [2, x, x]

# 2 is equal to 2, so let's place the two from nums2
        e
        i               j
-> [1, 2, 2, 3, 5, 6] , [x, x, x]
```

And we are done since there are no more elements left in `nums2` and we  
preserved the sortedness property of the array we are building during each  
iteration.

### Complexity

- Time: `O(m+n)`
- Space: `O(1)`

### Code

```cpp
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int e = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[e--] = nums1[i--];
            } else {
                nums1[e--] = nums2[j--];
            }
        }
    }
};
```
