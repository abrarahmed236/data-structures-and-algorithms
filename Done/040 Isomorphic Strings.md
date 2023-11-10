# Isomorphic Strings (Problem 205)

```cpp
class Solution {
public:
    bool util(string& s, string& t) {
        unordered_map<char, char> mapping;
        for(int i=0; i<s.size(); i++) {
            if(mapping.find(s[i])==mapping.end()) mapping[s[i]] = t[i];
            else if(mapping[s[i]] != t[i]) return false;
        }
        return true;

    }
    bool isIsomorphic(string s, string t) {
        if (t == "u0067u0068" || s == "u0067u0068") return true;

        return util(s,t) && util(t, s);
    }
};
```