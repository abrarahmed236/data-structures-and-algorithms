# Plus One (Problem 66)

Reverse the digits to make carrying easier.

```cpp
class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (int i = 0; i < digits.size(); i++) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
```

Iterate in reverse.

```cpp
class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (!carry) break;
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry) digits.insert(digits.begin(), carry);
        return digits;
    }
};
```
