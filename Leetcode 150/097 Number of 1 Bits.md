# Number of 1 Bits (Problem 191)

There are three-four equivalent ways to do this. All are interesting. All take
the same time.

```cpp
class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            if (n & 1) result++;
            n >>= 1;
        }
        return result;
    }
};
```
