# Ransom Note (Problem 383)

```cpp
class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[256] {0};
        for (char& c : magazine) cnt[c]++;
        for (char& c : ransomNote) {
            if (cnt[c]==0) return false;
            cnt[c]--;
        }
        return true;
    }
};
```