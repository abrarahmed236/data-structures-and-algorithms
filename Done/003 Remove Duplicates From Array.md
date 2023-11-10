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
of `0` or `1`, we don't need to make any changes.

And for `nums.size() >= 2`, we can iterate over the array and check if the  
current element is equal to the last included element. If it is equal then we  
append it to the beginning of the array, else we ignore it and go to the next  
iteration.

For this let's maintain two indices, `i, j`. `i` points to the last processed  
element and `j` points to the element that is to be processed in the current  
iteration. If `nums[j] == nums[i]`, then we have already included `nums[j]` in  
our array so we can ignore it and move on. If `nums[j] !] nums[i]`, then we  
need to include it by doing `i++; nums[i] = nums[j]`.

When we are done iterating over the array, we see that `i` points to the last  
processed element and there are `i+1` elements in the final array. We can  
ignore elements after `nums[i-1]`.

```text
-> [0 ,0 ,1 ,1 ,1 ,2 ,2 ,3 ,3 ,4]
# Let us consider the first element to be already processed

    i
       j
-> [0 ,0 ,1 ,1 ,1 ,2 ,2 ,3 ,3 ,4]
# nums[j] == nums[i], ignore and move on

    i
        ->j
-> [0 ,0 ,1 ,1 ,1 ,2 ,2 ,3 ,3 ,4]
# nums[j] != nums[i], include in final array

     ->i
           ->j
-> [0 ,1 ,1 ,1 ,1 ,2 ,2 ,3 ,3 ,4]
# nums[j] == nums[i], ignore and move on

       i
              ->j
-> [0 ,1 ,1 ,1 ,1 ,2 ,2 ,3 ,3 ,4]
# nums[j] == nums[i], ignore and move on

       i
                 ->j
-> [0 ,1 ,1 ,1 ,1 ,2 ,2 ,3 ,3 ,4]
# nums[j] != nums[i], include in final array

        ->i
                    ->j
-> [0 ,1 ,2 ,1 ,1 ,2 ,2 ,3 ,3 ,4]
# nums[j] == nums[i], ignore and move on


          i
                       ->j
-> [0 ,1 ,2 ,1 ,1 ,2 ,2 ,3 ,3 ,4]
# nums[j] != nums[i], include in final array

           ->i
                          ->j
-> [0 ,1 ,2 ,3 ,1 ,2 ,2 ,3 ,3 ,4]
# nums[j] == nums[i], ignore and move on

             i
                             ->j
-> [0 ,1 ,2 ,3 ,1 ,2 ,2 ,3 ,3 ,4]
# nums[j] != nums[i], include in final array

              ->i
                                ->j
-> [0 ,1 ,2 ,3 ,4 ,2 ,2 ,3 ,3 ,4]
# and we are done.
# i denotes the last element of the final array.
# return i+1
```

## Code

```cpp
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};
```
