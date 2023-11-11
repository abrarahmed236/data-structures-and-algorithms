# Reverse Bits (Problem 190)

Left Most and Right Most bit swapped
```cpp
class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int left = 0;
        int right = 31;
        while (left < right) {
            if (n & 1 << left) result |= 1 << right;
            if (n & 1 << right) result |= 1 << left;

            left++;
            right--;
        }
        return result;
    }
};
```

Pop first bit, push onto result, like a stack
```cpp
class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= n & 1;
            n >>= 1;
        }
        return result;
    }
};
```