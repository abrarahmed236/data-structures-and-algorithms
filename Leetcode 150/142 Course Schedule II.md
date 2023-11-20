# Course Schedule II (Problem 210)

Same as Course Schedule, Standard Topological Sort `//revisit`

```cpp
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& pre) {
        vector<vector<int>> adj(N, vector<int>());
        vector<int> degree(N, 0);  // In Degree
        for (auto& p : pre) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        queue<int> q;
        vector<int> result;
        for (int i = 0; i < N; i++)
            if (degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            for (int next : adj[curr]) {
                if (--degree[next] == 0) q.push(next);
            }
        }
        return result.size() == N ? result : vector<int>();
    }
};
```
