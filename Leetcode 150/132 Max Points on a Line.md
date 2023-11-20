# Max Points on a Line (Problem 149)

For each point P1, iterate over all other points P2 and remembering the slope
for each P2. Use the count of P2's for each slope w.r.t P1 to update max_count

```cpp
class Solution {
    double slope(vector<int> a, vector<int> b) {
        return static_cast<double>(b[1] - a[1]) /
               static_cast<double>(b[0] - a[0]);
    }

   public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) return points.size();
        int N = points.size();
        int max_count = INT_MIN;
        for (int i = 0; i < N; i++) {
            unordered_map<double, set<pair<int, int>>> counter;
            for (int j = i + 1; j < N; j++) {
                double slp = slope(points[i], points[j]);
                if (isinf(slp) && slp < 0) slp *= -1;
                counter[slp].insert({points[j][0], points[j][1]});
            }
            for (auto& p : counter) {
                max_count = max(max_count, (int)p.second.size() + 1);
            }
        }
        return max_count;
    }
};
```

We don't even need to remember the points, we can just count the number of
points P2 with the same slope.

```cpp
class Solution {
   public:
    int maxPoints(vector<vector<int>>& points) {
        int N = points.size();
        if (N < 3) return N;

        int max_count = INT_MIN;
        for (int i = 0; i < N; i++) {
            unordered_map<double, int> counter;
            for (int j = i + 1; j < N; j++) {
                double slp = (double)(points[j][1] - points[i][1]) /
                             (double)(points[j][0] - points[i][0]);
                if (isinf(slp) && slp < 0) slp *= -1;
                counter[slp]++;
            }
            for (auto& p : counter) {
                max_count = max(max_count, p.second + 1);
            }
        }

        return max_count;
    }
};
```
