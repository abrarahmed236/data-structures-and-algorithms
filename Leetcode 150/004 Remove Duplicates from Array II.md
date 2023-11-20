# [Remove Duplicates from Array II (Problem 80)](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

## Description

Given an integer array `nums` sorted in non-decreasing order, remove some  
duplicates in-place such that each unique element appears at most twice. The  
relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages,  
you must instead have the result be placed in the first part of the array  
`nums`. More formally, if there are `k` elements after removing the  
duplicates, then the first `k` elements of `nums` should hold the final  
result. It does not matter what you leave beyond the first `k` elements.

Return `k` after placing the final result in the first `k` slots of `nums`.

Do not allocate extra space for another array. You must do this by modifying  
the input array in-place with `O(1)` extra memory.

### Example 1

> **Input**: nums = [1,1,1,2,2,3]  
> **Output**: 5, nums = [1,1,2,2,3,_]  
> **Explanation**: Your function should return k = 5, with the first five  
> elements of nums being 1, 1, 2, 2 and 3 respectively. It does not matter  
> what you leave beyond the returned k (hence they are underscores).

### Example 2

> **Input**: nums = [0,0,1,1,1,1,2,3,3]  
> **Output**: 7, nums = [0,0,1,1,2,3,3,_,_]  
> **Explanation**: Your function should return k = 7, with the first seven  
> elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively. It does not  
> matter what you leave beyond the returned k (hence they are underscores).

### Constraints

- `1 <= nums.length <= 3 * 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in non-decreasing order.

## Approach

To solve this problem we can start with the smallest possible size of input  
array `nums`. If `nums.size() == 0 || nums.size() == 1 || nums.size() ==2`  
then we can return `K = nums.size()`, since these arrays have a maximum of one  
duplicate and all our input arrays are already sorted according to the  
description.

Now for the rest of the cases i.e `nums.size() >= 3`, let us keep an index  
that points to the last of the already processed elements (say `j`). Since we  
know that any array of size `2` is acceptable for us, we can consider the  
first two elements of `nums` as already processed. So we can set `j = 1` as we  
begin solving our problem.

Now we loop over the rest of the array and check if the current element (say  
`nums[i]`) is equal to the last processed element `nums[j]`. If they are not  
equal then we simply append the current element to the already processed  
elements. But if they are equal, then we need to consider the fact that we are  
allowed one duplicate. For this we can look at the last but one processed  
element `nums[j-1]`, if `nums[i] == nums[j-1]` then we have already processed  
a duplicate and we can ignore the current element from the final array. If  
`nums[i] != nums[j-1]` then we include the current element `nums[i]` in the  
final array.

> Note: Make it a point to look at the already included elements  
> `nums[j], nums[j-1]` for reference instead of `nums[i-1], nums[i-2]`, since  
> the latter may change unpredictably as we process elements.

### Code

```cpp
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        int j = 1;

        if (N <= 2) return N;

        for (int i = 2; i < N; i++) {
            if (nums[i] != nums[j] || nums[i] != nums[j - 1]) {
                nums[++j] = nums[i];
            }
        }

        return j + 1;
    }
};
```
