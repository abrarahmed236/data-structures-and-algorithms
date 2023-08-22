# [Jump Game (Problem 55)](https://leetcode.com/problems/jump-game/)

## Description

You are given an integer array `nums`. You are initially positioned at the
array's **first index**, and each element in the array represents your maximum
jump length at the position.

Return `true` if you can reach the **last index**, or false otherwise.

### Example 1

> **Input**: nums = [2,3,1,1,4]  
> **Output**: true  
> **Explanation**: Jump 1 step from index 0 to 1, then 3 steps to the last
> index.

### Example 2

> **Input**: nums = [3,2,1,0,4]  
> **Output**: false  
> **Explanation**: You will always arrive at index 3 no matter what. Its maximum
> jump length is 0, which makes it impossible to reach the last index.

### Constraints

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 10^5`

## Approach 1

A simple brute force solution to this problem is to try all possible jump
lengths, and if any path leads to the last index, then we return true. If no
path leads to the last index, then we return false.

### Code

```cpp
class Solution {
public:
    bool canJumpUtil(vector<int>& nums, int curr_index) {
        if(curr_index == nums.size()-1) return true;
        if(nums[curr_index]==0) return false;
        for(int i=1; i<=nums[curr_index] && curr_index+i<nums.size(); i++) {
            if(canJumpUtil(nums, curr_index+i)) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        return canJumpUtil(nums, 0);
    }
};
```

### Complexity

- **Time**: `O(N!)`
- **Space**: `O(N)`

This solution has a worst case time complexity of `N-factorial` since for each
starting location, we could end up looking at `N-1` sub-problems, each with a
separate recursive call. And it has a space complexity of `O(N)` for the
recursive call stack.

## Approach 2

The above solution is unacceptably bad. We could improve it by remembering
solutions to previous sub-problems. i.e memoization. If you can jump to a given
location, you don't need to check again as part of other sub-problems.

To do this, we can create a new array of booleans the same size as `nums`. We
set all elements of this array as `false` except for the first element which we
set as `true`.

Now for each reachable element from the beginning, we go through the array and
mark all further reachable elements.

If at the end we have the last element as reachable then we return `true`, else
we return `false`.

### Code

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Create a memo of reachable elements
        vector<bool> reachable(nums.size(), false);
        reachable[0] = true;

        // Mark all reachable elements from the beginning
        for(int i=0; i<nums.size()-1 && reachable[i]; i++) {
            for(int j=1; j<=nums[i] && i+j < nums.size(); j++) {
                reacheable[i+j] = true;
            }
            if(reachable[nums.size()-1])
                break;
        }
        return reachable[nums.size()-1];
    }
};
```

### Complexity

- **Time**: `O(N^2)`
- **Space**: `O(N)`

This solution has a time complexity of `N^2` because for each index we might
update all elements after that index. This leads us to a worst case of
`N-1 + N-2 + N-3 ... 2 + 1` updates. Which is `O(N^2)`.

## Approach 3

We can reduce the complexity of this problem further by starting at the last but
one element and seeing if the current element has enough jumps to reach the last
element. If the current element does have enough jumps to reach the end of the
array, then we can consider the problem solved for that part of the array and we
only need to look at earlier elements. But if the current element does not have
the required number of jumps to reach the last element we increment the required
number of jumps and look the previous element.

More clearly, from each element we need atleast 1 jump to move forward. If we
consider the solved part of the array on the right side as having enough jumps
to reach the end, then for the next element considered we need 1 jump to be able
to reach the end of the array. But say we encounter a zero while doing this.
What we can do is increase the number of required jumps for the next element to
2 and look at the next element. If the next element has >= 2 jumps then we are
good to go. if not then we increase the required number of jumps to 3 hoping the
next element has enough jumps. Once we cover the first element, if the number of
required jumps is greater than one, then we cannot reach the end of the array.

### Code

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        int required = 1;
        for(int i=N-2; i>=0; i--) {
            if(nums[i]<required) required++;
            else required = 1;
        }
        return required == 1;
    }
};
```

### Complexity

- **Time**: `O(N)`
- **Space**: `O(1)`
