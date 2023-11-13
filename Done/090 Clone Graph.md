# Clone Graph (Problem 133)

Simple Deep Copy the Graph

```cpp
class Solution {
    unordered_map<Node*, Node*> visited;

   public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (visited.find(node) != visited.end()) return visited[node];
        Node* newNode = new Node(node->val);
        visited[node] = newNode;
        for (auto& child : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(child));
        }
        return newNode;
    }
};
```

Alternately

```cpp
class Solution {
    Node* cloneGraphUtil(Node* node, unordered_map<Node*, Node*>& visited) {
        if (!node) return nullptr;
        if (visited.find(node) != visited.end()) return visited[node];
        Node* newNode = new Node(node->val);
        visited[node] = newNode;
        for (auto& child : node->neighbors) {
            newNode->neighbors.push_back(cloneGraphUtil(child, visited));
        }
        return newNode;
    }

   public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;
        return cloneGraphUtil(node, visited);
    }
};
```

Can use BFS too. But honestly it is too much trouble. Use DFS like above.
