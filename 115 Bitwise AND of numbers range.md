# Bitwise AND of numbers range (Problem 201)

Naive Method (TLE)

```cpp
class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        int result = right;
        for (int i = left; i < right; i++) {
            result &= i;
            if (result == 0) break;
        }
        return result;
    }
};
```

all bits where left != right get changed hence give zero on that bit. But some
bits in the beginning are the same. Those bits can contribute to the result and
nothing else. So, let's right shift left and right till they are equal. and
remember how much we shifted them back. Finally shift left back to that many
digits and return as result.

```cpp
class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0) return 0;
        int moved = 0;
        while(left != right) {
            left >>= 1;
            right >>= 1;
            moved++;
        }
        return left <<= moved;
    }
};
```
