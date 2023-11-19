# [Reverse words in a string (Problem 151)](https://leetcode.com/problems/reverse-words-in-a-string/)

```cpp
class Solution {
   public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result;

        while (ss >> word) {
            result = word + (result.empty() ? "" : " ") + result;
        }

        return result;
    }
};
```
