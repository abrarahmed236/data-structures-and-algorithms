# [Length of Last Word (Problem 58)](https://leetcode.com/problems/length-of-last-word/)

```cpp
class Solution {
   public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int len = 0;

        // skip spaces
        while (s[i--] == ' ');
        i++;

        // count word characters
        while (i >= 0 && s[i--] != ' ') {
            len++;
        }
        return len;
    }
};
```
