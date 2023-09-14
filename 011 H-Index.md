# [H-Index (Problem 274)](https://leetcode.com/problems/h-index/)


```cpp
class Solution {
   public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] < i + 1) return i;
        }
        return citations.size();
    }
};
```