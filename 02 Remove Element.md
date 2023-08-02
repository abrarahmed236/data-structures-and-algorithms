# [Remove Element (Problem 27)](https://leetcode.com/problems/remove-element)

## Description

Given an integer array `nums` and an integer `val`, remove all occurrences of  
`val` in `nums` in-place. The order of the elements may be changed. Then  
return the number of elements in `nums` which are not equal to `val`.

Consider the number of elements in `nums` which are not equal to `val` be `k`,  
to get accepted, you need to do the following things:

- Change the array `nums` such that the first `k` elements of `nums` contain  
  the elements which are not equal to `val`. The remaining elements of `nums`  
  are not important as well as the size of `nums`.
- Return `k`.

## Example 1

> **Input**: nums = [3,2,2,3], val = 3  
> **Output**: 2, nums = [2,2,_,_]  
> **Explanation**: Your function should return k = 2, with the first two  
> elements of nums being 2. It does not matter what you leave beyond the  
> returned k (hence they are underscores).

## Example 2

> **Input**: nums = [0,1,2,2,3,0,4,2], val = 2  
> **Output**: 5, nums = [0,1,4,0,3,_,_,_]  
> **Explanation**: Your function should return k = 5, with the first five  
> elements of nums containing 0, 0, 1, 3, and 4. Note that the five elements  
> can be returned in any order. It does not matter what you leave beyond the  
> returned k (hence they are underscores).

## Constraints

- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`

## Approach

This problem has a simple solution. We go through the array one element at a  
time and if the element is equal to `val` then we ignore it. Else we put the  
current element into the beginning of the array one after the other. We keep a  
count of the elements that we placed at the beginning of the array and return  
that number.

To do this we use two variables `i` and `j`, both initialized to zero. In each  
iteration we increment `i` after the processing the element at `Arr[i]`. While  
looking at `Arr[i]`, if `Arr[i] == val` then we ignore that element an move  
on. If `Arr[i] != val` then we write it to `Arr[j]` and increment `j`.

```text
#  Assume val is 2
    j
    i
-> [2, 2, 3, 4, 5, 2]
    j  i
-> [2, 2, 3, 4, 5, 2]
    j     i
-> [3, 2, 3, 4, 5, 2]
       j     i
-> [3, 4, 3, 4, 5, 2]
          j     i
-> [3, 4, 5, 4, 5, 2]
             j     i
-> [3, 4, 5, 4, 5, 2]
             j       i
-> [3, 4, 5, 4, 5, 2]
```

### Code

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;

        for(int i = 0; i<nums.size(); i++) {
            if(nums[i]!=val) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};
```
