# Longest Palindromic Sequence (Problem 5)

Add '.' between each character in string to make even sized palindromes easier
to process. For each mid point expand outwards while still palindrome.

```cpp
class Solution {
   public:
    string longestPalindrome(string s) {
        string temp;
        for (int i = 0; i < s.size(); i++) {
            if (i) temp.push_back('.');
            temp.push_back(s[i]);
        }

        int best_mid = 0;
        int best_off = 0;
        for (int i = 1; i < temp.size(); i++) {
            for (int j = 1; i - j >= 0 && i + j <= temp.size(); j++) {
                if (temp[i + j] == '.')
                    continue;
                else if (temp[i + j] == temp[i - j]) {
                    if (j > best_off) {
                        best_mid = i;
                        best_off = j;
                    }
                } else
                    break;
            }
        }

        string result;
        temp = temp.substr(best_mid - best_off, best_off * 2 + 1);
        for (char c : temp)
            if (c != '.') result.push_back(c);

        return result;
    }
};
```
