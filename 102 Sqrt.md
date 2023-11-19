# Sqrt (Problem 69)

Quick and Dirty using larger datatype

```cpp
class Solution {
   public:
    long sqr(long a) { return a * a; }
    int mySqrt(int x) {
        int result = 0;

        while (sqr(result + 1) <= (long)x) {
            result++;
        }

        return result;
    }
};
```

Cleaner code for above method
```cpp
class Solution {
   public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int result = 1;
        while (x / (result + 1) >= result + 1) result++;
        return result;
    }
};
```

But both above methods are O(sqrt(N)). We can do much better if we use binary search.
```cpp
// later
```