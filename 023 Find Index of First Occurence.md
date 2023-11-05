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

STL string find method

Similar performance, possibly because of small test sizes.
```cpp
class Solution {
   public:
    int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        return pos == string::npos ? -1 : static_cast<int>(pos);
    }
};
```
