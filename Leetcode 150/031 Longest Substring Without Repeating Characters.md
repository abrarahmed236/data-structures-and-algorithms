# Longest Substring Without Repeating Characters (Problem 3)


Simple sliding window with unordered_set to remember which elements have been seen.

```cpp
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int max_size = 0;
        int trailer = 0;
        unordered_set<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.find(s[i]) == st.end()) {
                st.insert(s[i]);
                max_size = max(max_size, (int)st.size());
            } else {
                while (!st.empty() && st.find(s[i]) != st.end()) {
                    st.erase(s[trailer]);
                    trailer++;
                }
                st.insert(s[i]);
            }
        }
        return max_size;
    }
};
```

Cleaner code
```cpp
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int max_size = 0;
        int trailer = 0;
        unordered_set<char> st;
        for (int i = 0; i < s.size(); i++) {
            while (!st.empty() && st.find(s[i]) != st.end()) {
                st.erase(s[trailer]);
                trailer++;
            }
            st.insert(s[i]);
            if (st.size() > max_size) max_size = st.size();
        }
        return max_size;
    }
};
```

Same as above but use a vector bool to remember seen elements (marginally better solution)
```cpp
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int max_size = 0;
        int curr_size = 0;
        int trailer = 0;
        vector<bool> st(256, false);
        for (int i = 0; i < s.size(); i++) {
            char curr_char = s[i];
            while (curr_size && st[curr_char]) {
                st[s[trailer]] = false;
                trailer++;
                curr_size--;
            }
            st[curr_char] = true;
            curr_size++;
            max_size = max(max_size, curr_size);
        }
        return max_size;
    }
};
```

Remember latest seen location of a character in the vector bool ins tead, (as good as it gets)
```cpp
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(256, -1);
        int max_size = 0, start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (last_seen[s[i]] > start) start = last_seen[s[i]];
            last_seen[s[i]] = i;
            max_size = max(max_size, i - start);
        }
        return max_size;
    }
};
```