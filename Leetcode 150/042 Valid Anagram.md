# Valid Anagram (Problem 242)

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp(256, 0);
        for(char& c: t) mp[c]++;
        for(char& c: s) mp[c]--;
        for(int& n:mp) if(n) return false;
        return true;
    }
};
```