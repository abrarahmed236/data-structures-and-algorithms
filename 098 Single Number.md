# Single Number (Problem 136)

Use xor

```cpp
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto& n : nums) result ^= n;
        return result;
    }
};
```

can possibly do better.
