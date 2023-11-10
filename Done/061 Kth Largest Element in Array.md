# Kth Largest Element in Array (Problem 215)

Priority Queue Straight Forward

```cpp
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int& n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
```

Sorting and returning Kth element

```cpp
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};
```

Using inbuild nth element

```cpp
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(),
                    greater<int>());
        return nums[k - 1];
    }
};
```
