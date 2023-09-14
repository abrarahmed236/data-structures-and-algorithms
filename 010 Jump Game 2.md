# [Jump Game 2 (Problem 45)](https://leetcode.com/problems/jump-game-ii/)

## Description

You are given a **0-indexed** array of integers `nums` of length `n`. You are
initially positioned at `nums[0]`.

Each element `nums[i]` represents the maximum length of a forward jump from
index `i`. In other words, if you are at `nums[i]`, you can jump to any
`nums[i+j]` where:

- `0 <= j <= nums[i]` and
- `i+j < n`

Return the minimum number of jumps to reach `nums[n-1]`. The test cases are
generated such that you can reach `nums[n-1]`.

### Example 1

> **Input**: nums = [2, 3, 1, 1, 4]  
> **Output**: 2  
> **Explanation**: The minimum number of jumps to reach the last index is 2.  
> Jump 1 step from index 0 to 1, then 3 steps to the last index.

### Example 2

> **Input**: nums = [2, 3, 0, 1, 4] > **Output**: 2

### Constraints

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 1000`
- It is guaranteed that you can reach `nums[n-1]`.

## Approach 1

Let us start with a brute force approach. We know that if we are at index `n-1`,
then it takes us `0` steps to reach the last index. And any index that can
directly reach `n-1` needs `1` jump. So we can extrapolate this and write a
recursive function where the base case is that it takes `0` jumps to reach `n-1`
from `n-1` and one additional jump for each parent recursion above it.

### Code

```cpp
class Solution {
   public:
    int jumpUtil(vector<int>& nums, int i) {
        // Base case
        if (i == nums.size() - 1) return 0;

        // Minimum of all possible jumps from this position
        int minJumps = INT_MAX;
        for (int j = 1; j <= nums[i] && j + i < nums.size(); j++) {
            int jumps = jumpUtil(nums, i + j);
            if (jumps != INT_MAX && jumps + 1 < minJumps) {
                minJumps = jumps + 1;
            }
        }
        return minJumps;
    }
    int jump(vector<int>& nums) {
        return jumpUtil(nums, 0);
    }
};
```

### Complexity

- **Time**: `O(N^N)`
- **Space**: `O(N)`

### Discussion

Now our solution has an atrocious time complexity. Which makes this solution
useless, but we can improve this solution dramatically by adding memoization.

## Approach 2: Memoization

To add memoization to a problem like this, we need to identify where the
repeated sub-problems are. And we need to identify when the sub-problems are
completely solved.

We know that at index `n-1`, the number of jumps required is `0`. So this
sub-problem is completely solved. Next, we know that every index that can reach
`n-1` in one step can be solved next without hesitation. From here on out we can
build a memo of solutions.

Let us have a `memo` array the same size as `nums`. Initialize every element to
`-1` to indicate that we don't have a solution yet. Then let us mark
`memo[n-1] = 0` to indicate our base case.

Now in the above code when we encounter an unvisited index, we note down the
minimum from all possible jump locations, but if we have visited the node
already, we take the solution from the memo and return it instead of recursing
further.

### Code

```cpp
class Solution {
   public:
    int jumpUtil(vector<int>& nums, int i, vector<int>& memo) {
        if (i == nums.size() - 1) return 0;
        if (memo[i] != -1) return memo[i];
        int minJumps = INT_MAX;
        for (int j = 1; j <= nums[i] && j + i < nums.size(); j++) {
            int jumps = jumpUtil(nums, i + j, memo);
            if (jumps != INT_MAX && jumps + 1 < minJumps) {
                minJumps = jumps + 1;
            }
        }
        return memo[i] = minJumps;
    }
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        memo.back() = 0;
        return jumpUtil(nums, 0, memo);
    }
};
```

### Complexity

- **Time**: `O(N^2)`
- **Space**: `O(N)`

### Discussion

The space complexity is `O(N)` for both the recursive call stack and the memo
itself. And the time complexity is amazingly reduced to `O(N^2)` from an
atrocious `O(N^N)`. The time complexity is `O(N^2)` because we call the
recursive function `N-1` times in the worst case from the first position, but
from each of these positions the inner loop runs `O(N)` times. Further recursion
is stopped by memoization.

## Approach 3: Tabulation

We can approach this same problem from the bottom up and build up a table of
minimum jumps from the first index.

For this we mark, the number of jumps requird for first index as zero. Then we
mark all indices reachable from the first index as 1. From now on we mark all
indices reachable from subsequent indices as the minimum of the current jumps
and the stored jumps.

### Code

```cpp
class Solution {
   public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        vector<int> memo(N, INT_MAX);
        memo[0] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= nums[i] && i + j < N; j++) {
                memo[i + j] = min(memo[i + j], memo[i] + 1);
            }
        }
        return memo.back();
    }
};
```

### Complexity

- **Time**: `O(N^2)`
- **Space**: `O(N)`

### Discussion

All above solutions rely on brute-forcing the problem and then further
optimizing. But they do not take into account the nature of the problem.

## Approach 4: Optimal Solution

We can take into account that at each index we know how far we can go with the
distance allowed from that index. i.e we know i+nums[i] viz the furthest index
we can reach in one jump.

We can use this information to keep track of max distance we can travel before
we have to consider ourselves as having jumped and also how far we can travel in
the next jump.

```cpp
class Solution {
   public:
    int jump(vector<int>& nums) {
        int currentFarthest = 0;
        int nextFarthest = nums[0];
        int jumps = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > currentFarthest) {
                jumps++;
                currentFarthest = nextFarthest;
            }
            nextFarthest = max(nextFarthest, i + nums[i]);
            if (nextFarthest < i) return -1;
        }
        return jumps;
    }
};
```

### Complexity

- **Time**: `O(N)`
- **Space**: `O(1)`

### Discussion

This is the best complexity possible with this problem.
