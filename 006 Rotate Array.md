# [Rotate Array (Problem 189)](https://leetcode.com/problems/rotate-array/)

## Description

Given an integer array `nums`, rotate the array to the right by `k` steps,  
where `k` is non-negative.

### Example 1

> **Input**: nums = [1,2,3,4,5,6,7], k = 3  
> **Output**: [5,6,7,1,2,3,4]  
> **Explanation**:  
> rotate 1 steps to the right: [7,1,2,3,4,5,6]  
> rotate 2 steps to the right: [6,7,1,2,3,4,5]  
> rotate 3 steps to the right: [5,6,7,1,2,3,4]

### Example 2

> **Input**: nums = [-1,-100,3,99], k = 2  
> **Output**: [3,99,-1,-100]  
> **Explanation**:  
> rotate 1 steps to the right: [99,-1,-100,3]  
> rotate 2 steps to the right: [3,99,-1,-100]

### Constraints

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`
- `0 <= k <= 10^5`

> Could you do it in `O(1)` extra space ?

## Approach 1

We can write a function to rotate one step to the right. And we can call this  
function `k` times.

### Code

```cpp
class Solution {
   public:
    void rightRotate(vector<int>& nums) {
        if (nums.size() == 0) return;
        int temp = nums.back();
        for (int i = nums.size() - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }
        nums[0] = temp;
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        for (int i = 0; i < k; i++) {
            rightRotate(nums);
        }
    }
};
```

### Complexity

- **Time**: `O(n^2)`
- **Space**: `O(1)`

This approach takes `O(n^2)` time since the `rightRotate()` function takes  
`O(n)` time and it is called `O(n)` times.

## Approach 2

The problem with the above approach is we that we are repeatedly taking small  
steps when we could simply take large steps when shifting if we had enough  
space to store the elements which are to be shifted over the edge.

For this we can use a temporary array. In this temporary array we store the  
last `k` elements of `nums`. And then we shift all elements of `nums`, `k`  
steps to the right. And finally we write the contents of the temporary array  
to the first `k` elements of `nums`.

### Code

```cpp
class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(k);
        int N = nums.size();
        k = k % N;

        // store last k elements in temporary array
        for (int i = N - k; i < N; i++) {
            temp [i - (N - k)] = nums[i];
        }
        // shift elements k steps to the right
        for (int i = N - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }
        // write back the contents of temporary
        // array to the beginning of nums
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
```

### Complexity

- **Time**: `O(n)`
- **Space**: `O(n)`

This approach reduces our time complexity to `O(n)` but it does so at the cost  
of a space complexity of `O(n)`.

## Approach 3

There is a way to solve this problem in `O(n)` time while using only `O(1)`  
space. For this we reverse the whole array to begin with. This puts the last  
`k` elements at the front of the array and the first `N-k` elements at the  
back. Then we reverse the first `k` elements and the last `N-k` elements of the  
array. This fixes the ordering of the elements.

```text
-> [1, 2, 3, 4, 5, 6, 7] k = 3

#  Reverse the whole array
-> [7, 6, 5, 4, 3, 2, 1]

#  Reverse the first k elements
-> [5, 6, 7, 4, 3, 2, 1]

#  Reverse the last N-k elements
-> [5, 6, 7, 1, 2, 3, 4]

#  This is our desired result
```

### Code

```cpp
class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```

### Complexity

- **Time**: `O(n)`
- **Space**: `O(1)`
