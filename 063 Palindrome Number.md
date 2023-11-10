# Palindrome Number (Problem 9)

Convert to string and check for palindrome
```cpp
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string num = to_string(x);
        int i = 0, j = num.size() - 1;
        while (i < j) {
            if (num[i++] != num[j--]) return false;
        }
        return true;
    }
};
```