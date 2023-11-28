# Number of Connected Components

[Connected Components in a Graph](https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/)

Straight Forward DFS Traversal

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void DFS(int curr, vector<vector<int>>& adj, vector<int>& visited) {
    if (visited[curr]) return;
    visited[curr] = 1;
    for (int neighbour : adj[curr])
        if (!visited[neighbour]) DFS(neighbour, adj, visited);
}

int get_connected_components(vector<vector<int>>& adj, vector<int>& visited) {
    int N = visited.size();
    queue<int> Q;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            DFS(i, adj, visited);
            count++;
        }
    }
    return count;
}

int main() {
    int N, E;
    cin >> N >> E;
    vector<vector<int>> adj(N);
    vector<int> visited(N);
    while (E--) {
        int A, B;
        cin >> A >> B;
        adj[A - 1].push_back(B - 1);
        adj[B - 1].push_back(A - 1);
    }
    cout << get_connected_components(adj, visited) << endl;
    return 0;
}
```

Very Similar BFS Traversal

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int get_connected_components(vector<vector<int>>& adj, vector<int>& visited) {
    int N = visited.size();
    queue<int> Q;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        Q.push(i);
        count++;
        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            visited[curr] = 1;
            for (int neighbour : adj[curr])
                if (!visited[neighbour]) Q.push(neighbour);
        }
    }
    return count;
}

int main() {
    int N, E;
    cin >> N >> E;
    vector<vector<int>> adj(N);
    vector<int> visited(N);
    while (E--) {
        int A, B;
        cin >> A >> B;
        adj[A - 1].push_back(B - 1);
        adj[B - 1].push_back(A - 1);
    }
    cout << get_connected_components(adj, visited) << endl;
    return 0;
}
```

Union Find Algorighm `//revisit`

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>

using namespace std;

int my_find(int node, vector<int>& parent) {
    int result = node;
    while (result != parent[result]) {
        parent[result] = parent[parent[result]];  // path compression
        result = parent[result];
    }
    return result;
}

int my_union(int node1, int node2, vector<int>& parent, vector<int>& rank) {
    int p1 = my_find(node1, parent);
    int p2 = my_find(node2, parent);

    if (p1 == p2) return 0;

    if (rank[p2] > rank[p1]) {
        parent[p1] = p2;
        rank[p2] += rank[p1];
    } else {
        parent[p2] = p1;
        rank[p1] += rank[p2];
    }
    return 1;
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<int> parent(N);
    iota(parent.begin(), parent.end(), 0);
    vector<int> rank(N, 1);

    int result = N;
    while (E--) {
        int A, B;
        cin >> A >> B;

        result -= my_union(A - 1, B - 1, parent, rank);
    }
    cout << result << endl;

    return 0;
}
```

Union Find with slightly different path compression

```cpp
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int my_find(int node, vector<int>& parent) {
    if (node != parent[node]) {
        parent[node] = my_find(parent[node], parent);  // path compression
    }
    return parent[node];
}

int my_union(int node1, int node2, vector<int>& parent, vector<int>& rank) {
    int p1 = my_find(node1, parent);
    int p2 = my_find(node2, parent);

    if (p1 == p2) return 0;

    if (rank[p1] < rank[p2]) {
        parent[p1] = p2;
        rank[p2] += rank[p1];
    } else {
        parent[p2] = p1;
        rank[p1] += rank[p2];
    }
    return 1;
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<int> parent(N);
    iota(parent.begin(), parent.end(), 0);
    vector<int> rank(N, 1);

    int result = N;
    while (E--) {
        int A, B;
        cin >> A >> B;

        result -= my_union(A - 1, B - 1, parent, rank);
    }
    cout << result << endl;

    return 0;
}
```
