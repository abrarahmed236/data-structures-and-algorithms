# Course Schedule (Problem 207)

Standard Topological Sort `//revisit`

```cpp
class Solution {
   public:
    bool canFinish(int N, vector<vector<int>>& pre) {
        vector<vector<int>> adj(N, vector<int>());
        vector<int> degree(N, 0);  // In Degree
        for (auto& p : pre) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        queue<int> q;
        int count = 0;
        for (int i = 0; i < N; i++)
            if (degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;
            for (int next : adj[curr]) {
                if (--degree[next] == 0) q.push(next);
            }
        }
        return count == N;
    }
};
```
