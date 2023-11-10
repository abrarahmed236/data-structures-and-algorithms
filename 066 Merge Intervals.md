# Merge Intervals (Problem 56)

Sort the intervals by their beginning time.  
Then merge an interval with the previous one if there is an overlap.  
Iterate

```cpp
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;
        result.reserve(intervals.size());
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (prev[1] >= intervals[i][0]) {
                prev[1] = max(prev[1], intervals[i][1]);
            } else {
                result.push_back(prev);
                prev = intervals[i];
            }
        }
        result.push_back(prev);
        return result;
    }
};
```
