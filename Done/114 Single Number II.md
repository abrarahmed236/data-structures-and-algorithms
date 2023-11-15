# Single Number II (Problem 137)

Maintiain a counter for each bit position. (i.e 32 counters) For each number
update the 32 counters. For each bit in the result. use 1 if counter[i] % 3 == 1
else use 0. This is because for all numbers that have 3 repetitions, counter[i]
% 3 == 0. for all i. This is only different for the one number that occurs only
once.

```cpp
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32, 0);
        for (int n : nums) {
            for (int i = 0; i < 32; i++) {
                if (n & 1 << i) cnt[i]++;
            }
        }
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (cnt[i] % 3) result |= 1 << i;
        }
        return result;
    }
};
```

Fancy general purpose method from here:
[Link](https://leetcode.com/problems/single-number-ii/solutions/43295/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers/?envType=study-plan-v2&envId=top-interview-150)

```cpp
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0, mask = 0;

        for (int& i : nums) {
            x2 ^= x1 & i;
            x1 ^= i;
            mask = ~(x1 & x2);
            x2 &= mask;
            x1 &= mask;
        }

        return x1;
    }
};
```
