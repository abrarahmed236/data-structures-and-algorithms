# Word Pattern (Problem 290)

```cpp
class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string temp;
        while (ss >> temp) {
            words.push_back(temp);
        }
        if (pattern.size() != words.size()) return false;
        unordered_map<char, string> mp;
        unordered_map<string, char> mp1;
        for (int i = 0; i < pattern.size(); i++) {
            if (mp.find(pattern[i]) == mp.end())
                mp[pattern[i]] = words[i];
            else if (mp[pattern[i]] != words[i])
                return false;
            if (mp1.find(words[i]) == mp1.end())
                mp1[words[i]] = pattern[i];
            else if (mp1[words[i]] != pattern[i])
                return false;
        }
        return true;
    }
};
```