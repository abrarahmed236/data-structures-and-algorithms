# [Remove Duplicates from Array (Problem 26)](https://leetcode.com/problems/remove-duplicates-from-sorted-array)

## Description

Given an integer array `nums` sorted in non-decreasing order, remove the  
duplicates in-place such that each unique element appears only once. The  
relative order of the elements should be kept the same. Then return the  
number of unique elements in `nums`.

Consider the number of unique elements of `nums` to be `k`, to get accepted,  
you need to do the following things:

Change the array `nums` such that the first `k` elements of `nums` contain  
the unique elements in the order they were present in `nums` initially. The  
remaining elements of `nums` are not important as well as the size of `nums`.  
Return `k`.

### Example 1

> **Input**: nums = [1,1,2]  
> **Output**: 2, nums = [1,2,_]  
> **Explanation**: Your function should return k = 2, with the first two  
> elements of nums being 1 and 2 respectively. It does not matter what you  
> leave beyond the returned k (hence they are underscores).

### Example 2

> Input: nums = [0,0,1,1,1,2,2,3,3,4]  
> Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]  
> Explanation: Your function should return k = 5, with the first five elements  
> of nums being 0, 1, 2, 3, and 4 respectively. It does not matter what you  
> leave beyond the returned k (hence they are underscores).

### Constraints

- `1 <= nums.length <= 3 * 10^4`
- `-100 <= nums[i] <= 100`
- `nums` is sorted in non-decreasing order.

## Approach

This problem also has a simple and elegant solution. If the `nums` has a size  
of `0` or `1`, we don't need to make any changes. The problem is non-trivial  
from `nums.size() >= 2`. From here we can safely look at the second element  
without going over array bounds. So in our solution we start from the second  
element and process each element. If it is the same as the previous element  
then we ignore it and move on. If it is not the same then we add this element  
to the beginning of the array.

To achieve this we will have two indices (or iterators). Both pointing to the  
second element in the array. Let's call them `i` and `j`. Let's use `j` to  
denote the elements that have already been processed and next location where  
an element can be added is `Arr[j]`. We consider every element before `Arr[j]`  
to be sorted and non-duplicated. This is true in the beginning when `j == 1`.  
From now on if `Arr[j] == Arr[j-1]` we are not intereested in the element at  
`j`. So we ignore it and move on. And if `Arr[j] != Arr[j-1]` we want that  
element in our final array so we do `Arr[i] = Arr[j]` and increment `j`.

When we are done we will have sorted non-duplicate elements in  
`Arr[0]...A[j-1]` and `j` indicates the number of elements in our array.

## Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        int n = nums.size();
        for(int j=1; j<n; j++) {
            if(nums[j]!=nums[j-1]) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
```
