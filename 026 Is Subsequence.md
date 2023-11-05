# Is Subsequence (Problem 168)

Simple inituitive solution.

```cpp
class Solution {
   public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0) return true;

        int i = 0;
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) i++;
        }

        return i == s.length();
    }
};
```