# Factorial Trailing Zeroes (Problem 172)

Quick and Dirty.

```cpp
class Solution {
   public:
    int trailingZeroes(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            int temp = i;
            while (temp % 5 == 0) {
                result++;
                temp /= 5;
            }
        }
        return result;
    }
};
```

Cleaner solution

```cpp
class Solution {
   public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n > 0) {
            result += n / 5;
            n /= 5;
        }
        return result;
    }
};
```
