# Minimum Number of Arrows to Burst Balloons (Problem 452)

Sort the intervals.  
Accumulate intersections.  
Return count of intersections.

```cpp
class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
             });

        int counter = 1;
        vector<int> prev = points[0];
        for (int i = 1; i < points.size(); i++) {
            int begin = max(prev[0], points[i][0]);
            int end = min(prev[1], points[i][1]);
            if (begin <= end) {
                prev[0] = begin;
                prev[1] = end;
            } else {
                prev[0] = points[i][0];
                prev[1] = points[i][1];
                counter++;
            }
        }

        return counter;
    }
};
```
