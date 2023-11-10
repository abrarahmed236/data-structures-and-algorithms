# Longest Consecutive Sequence (Problem 128)

Using sorting. Even though nlogn, performs really well.

```cpp
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        if(nums.size() < 2) return nums.size();
        int count = 1, max_count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                count++;
            } else {
                count = 1;
            }
            if (count > max_count) max_count = count;
        }
        return max_count;
    }
};
```

We can use the ordered property of set<int> container, but that just performs
slower, leaning more towards nlogn

```cpp
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for (int& n : nums) st.insert(n);
        if (st.size() < 2) return st.size();
        int count = 1, max_count = 1;
        auto it = st.begin();
        while (next(it) != st.end()) {
            if (*it + 1 == *next(it))
                count++;
            else
                count = 1;
            if (count > max_count) max_count = count;
            it++;
        }
        return max_count;
    }
};
```
