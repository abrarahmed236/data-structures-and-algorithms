# [Roman to Integer (Problem 13)](https://leetcode.com/problems/roman-to-integer/)

```cpp
class Solution {
   public:
    int romanToInt(string s) {
        unordered_map<char, int> value{
            {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000},
        };

        int result = 0;
        int prev = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int curr = value[s[i]];
            result += (curr < prev ? -1 : 1) * curr;
            prev = curr;
        }
        return result;
    }
};
```