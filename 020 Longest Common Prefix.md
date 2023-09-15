# [Longest Common Prefix (Problem 14)](https://leetcode.com/problems/longest-common-prefix/)

```cpp
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";

        int pos = 0;
        bool valid = true;
        while (valid) {
            if (pos >= strs[0].size()) break;
            char curr = strs[0][pos];
            for (int i = 1; i < strs.size(); i++) {
                if (pos >= strs[i].size() || curr != strs[i][pos]) {
                    valid = false;
                    break;
                }
            }

            if (valid) result.push_back(curr);
            pos++;
        }

        return result;
    }
};
```
