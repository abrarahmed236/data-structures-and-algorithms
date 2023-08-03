# [Majority Element (Problem 169)](https://leetcode.com/problems/majority-element/)

## Description

Given an array `nums` of size `n`, return the majority element.

The majority element is the element that appears more than `⌊n / 2⌋` times.  
You may assume that the majority element always exists in the array.

### Example 1

> **Input**: nums = [3,2,3]  
> **Output**: 3

### Example 2

> **Input**: nums = [2,2,1,1,1,2,2]  
> **Output**: 2

### Constraints

- `n == nums.length`
- `1 <= n <= 5 * 10^4`
- `-10^9 <= nums[i] <= 10^9`

## Approach 1

We can approach this problem by simply keeping a count of each encountered  
element in the array. And if we see that any element has a `count > n/2` we  
simply return that element.

For this we would need some sort of counter. We could use an array, but with  
`-10^9 <= nums[i] <= 10^9` the array would be huge and much larger than  
`n <= 5*10^4`. So instead we can use a map to count. In C++ you can use  
`map<int, int>` or `unordered_map<int, int>` to do this. Since we do not need  
the key elements to be ordered in this approach, we can use  
`unordered_map<int, int>` which gives us `O(1)` time complexity for access and  
insertion.

### Code

```cpp
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> count;
        for (int i = 0; i < N; i++) {
            count[nums[i]]++;
            if (count[nums[i]] > N / 2) return nums[i];
        }
        return INT_MIN;
    }
};
```

### Complexity

- **Time**: `O(n)`
- **Space**: `O(n)`

This approach gives us a time complexity of `O(n)` which is the best we can do  
for this problem, but it does require `O(n)` space, which can be reduced with  
other approaches.

## Approach 2

If we don't want to use `O(n)` space to maintain the counts of each element we  
could sort the array and rely on the fact that if there is one element in the  
array with more than `n/2` occurences, then once sorted, we will definitely  
find that number at `nums[n/2]`.

### Code

```cpp
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
```

### Complexity

- **Time**: `O(n*log(n))`
- **Space**: `O(1)`

This approach give us constant space complexity but ends up giving us a worse  
`O(n*log(n))` time complexity. We can use this approach for it's simplicity  
and for the fact that library sort tends to be quite efficient and for most  
purposes it gives us a more robust implementation. But it is still worse time
complexity.

## Approach 3

To deal with this conundrum of trading time and space complexity we have  
another option for this problem. We can use the **Boyer-Moore voting
algorithm**.

This is an optimal algorithm for finding the majority element and it works by  
keeping track of a current `candidate` winner and that candidate's `count`.  
Every time we see encounter our `candidate` in the array we increment its  
`count`. If we see a number other than the candidate then we decrement the  
`count`. But if we see that the count has gone to zero, then we take the next  
element we encounter to be our next `candidate`.

The **Boyer-Moore voting algorithm** relies on the fact that if there are  
`> n/2` occurences of a given element, then it is garuanteed to win this  
voting scheme because the majority candidate always has a lead on the rest of  
the candidates due to sheer number.

### Code

```cpp
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int N = nums.size();
        int candidate, count = 0;
        for (int i = 0; i < N; i++) {
            if (!count) {
                candidate = nums[i];
                count = 1;
            } else if (candidate == nums[i])
                count++;
            else
                count--;
        }
        return candidate;
    }
};
```

### Complexity

- **Time**: `O(n)`
- **Space**: `O(1)`
