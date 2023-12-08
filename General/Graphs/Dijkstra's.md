# Rough Implementation of Dijkstra's Algorithm for getting shortest paths

- [ ] Revisit
- [ ] Find problem specifically for this

[Dijkstra's Problems](https://leetcode.com/list/53js48ke/)

Standard Algorithm:

```cpp
class Solution {
   public:
    int minDist(const vector<int> &dist, const vector<int> &visited) {
        int min_dist = INT_MAX, min_ind;
        for (int v = 1; v < dist.size(); v++) {
            if (!visited[v] && dist[v] <= min_dist) {
                min_dist = dist[v];
                min_ind = v;
            }
        }
        return min_ind;
    }
    vector<int> shortest_paths(vector<vector<int>> &edges, int V, int k) {
        // Vector of distances and the set of visited vertices
        vector<int> dist(V + 1, INT_MAX);  // Index 0 ignored
        vector<int> visited(V + 1, 0);     // Index 0 ignored

        // Construct Adjacency Matrix from edges
        vector<vector<int>> adj(V + 1, vector<int>(V + 1));  // Index 0 ignored
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]][edges[i][1]] = edges[i][2];
        }

        dist[k] = 0;

        // Iterate over remaining vertices
        for (int count = 0; count < V; count++) {
            // Get the closest unvisited neighbour
            int u = minDist(dist, visited);
            if (dist[u] == INT_MAX) return -1;
            cout << u << endl;

            visited[u] = 1;

            // Update all neighbours of u
            for (int v = 1; v <= V; v++) {
                if (!visited[v] && adj[u][v] && dist[u] != INT_MAX)
                    dist[v] = min(dist[v], dist[u] + adj[u][v]);
            }
        }

        // Now we have the shortest paths
        return dist;
    }
};
```

Good Dijkstra's Question: 1514. Path With Maximum Probability.  
But needs a priority queue to implement properly.

```cpp
class Solution {
   public:
    int get_min(const vector<double> &dist, const vector<int> &visited) {
        int min_ind;
        double max_prob = numeric_limits<double>::lowest();
        for (int v = 0; v < dist.size(); v++) {
            if (!visited[v] && dist[v] >= max_prob) {
                max_prob = dist[v];
                min_ind = v;
            }
        }
        return min_ind;
    }

    double maxProbability(int V, vector<vector<int>> &edges,
                          vector<double> &succProb, int start_node,
                          int end_node) {
        vector<double> dist(V, 0);
        vector<int> visited(V, 0);

        vector<vector<double>> adj(V, vector<double>(V, 0));
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]][edges[i][1]] = succProb[i];
            adj[edges[i][1]][edges[i][0]] = succProb[i];
        }

        dist[start_node] = 1;  // 100 % probability
        for (int count = 0; count < V; count++) {
            int u = get_min(dist, visited);
            visited[u] = 1;
            for (int v = 0; v < V; v++) {
                if (!visited[v] && adj[u][v] > 0 && dist[u] != 0) {
                    dist[v] = max(dist[v], dist[u] * adj[u][v]);
                }
            }
        }
        return dist[end_node];
    }
};
```

Combination of adjacency list and priority queue gives good times.

```cpp
class Solution {
   public:
    double maxProbability(int V, vector<vector<int>> &edges,
                          vector<double> &succProb, int start_node,
                          int end_node) {
        vector<double> dist(V, 0);

        vector<vector<pair<int, double>>> adj(V);  // adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        set<pair<double, int>> Q;

        Q.insert({1, start_node});
        dist[start_node] = 1;
        while (!Q.empty()) {
            int u = Q.rbegin()->second;
            Q.erase(prev(Q.end()));

            for (auto [v, w] : adj[u]) {
                if (dist[u] * w > dist[v]) {
                    Q.erase({dist[v], v});
                    dist[v] = dist[u] * w;
                    Q.insert({dist[v], v});
                }
            }
        }

        return dist[end_node];
    }
};
```

Similarly, this question works well with dijkstra's  
743. Network Delay Time

```cpp
class Solution {
   public:
    int networkDelayTime(vector<vector<int>> &edges, int V, int S) {
        vector<int> dist(V, INT_MAX);

        vector<vector<pair<int, int>>> adj(V);  // adjacency list
        for (auto edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        set<pair<int, int>> Q;
        dist[S - 1] = 0;
        Q.insert({0, S - 1});
        while (!Q.empty()) {
            int u = Q.begin()->second;
            Q.erase(Q.begin());
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    Q.erase({dist[v], v});
                    dist[v] = dist[u] + w;
                    Q.insert({dist[v], v});
                }
            }
        }

        int result = *max_element(dist.begin(), dist.end());
        return result == INT_MAX ? -1 : result;
    }
};
```
