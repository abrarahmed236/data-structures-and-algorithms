# Problem for Bellman Ford

743. Network Delay Time

```cpp
class Solution {
   public:
    int networkDelayTime(vector<vector<int>> &times, int V, int k) {
        vector<int> distance(V, INT_MAX);
        vector<int> predecessor(V, -1);

        distance[k - 1] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (auto edge : times) {
                int u = edge[0] - 1;
                int v = edge[1] - 1;
                int w = edge[2];
                if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    predecessor[v] = u;
                }
            }
        }

        int result = *max_element(distance.begin(), distance.end());
        return result == INT_MAX ? -1 : result;
    }
};
```
