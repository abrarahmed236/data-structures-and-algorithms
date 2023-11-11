# Insert Interval (Problem 57)

Quick and Dirty

```cpp
class Solution {
    const static int debug = true;

   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> result;
        int N = intervals.size();
        vector<int> lapped;
        auto overlap = [&](vector<int>& a, vector<int>& b) {
            if (a[0] >= b[0] && a[0] <= b[1]) return true;
            if (a[1] >= b[0] && a[1] <= b[1]) return true;
            if (b[0] >= a[0] && b[0] <= a[1]) return true;
            if (b[1] >= a[0] && b[1] <= a[1]) return true;

            return false;
        };
        for (int i = 0; i < N; i++) {
            if (overlap(intervals[i], newInterval)) {
                if (debug)
                    cout << "found lap: "
                         << " ";
                lapped.push_back(i);
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                if (debug)
                    cout << newInterval[0] << " " << newInterval[1] << endl;
            }
        }
        int i;
        for (i = 0; i < N; i++) {
            if (lapped.size() > 0 && i == lapped.front()) break;
            if (intervals[i][1] >= newInterval[0]) break;
            result.push_back(intervals[i]);
        }
        result.push_back(newInterval);
        while (lapped.size() > 0 && i <= lapped.back()) i++;
        for (; i < N; i++) {
            result.push_back(intervals[i]);
        }
        return result;
    }
};
```

As good as it gets

```cpp
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> result;
        int N = intervals.size();

        int i = 0;
        while (i < N && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        while (i < N && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        while (i < N) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};
```
