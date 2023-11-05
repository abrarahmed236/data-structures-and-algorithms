# Find Index of First Occurence (Problem 28)


Brute force search

Not a bad solution.

```c++
class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        for (int i = 0; i < (haystack.size() - needle.size() + 1); i++) {
            bool not_found = false;
            for (int j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    not_found = true;
                    break;
                }
            }
            if (not_found == false) return i;
        }
        return -1;
    }
};
```