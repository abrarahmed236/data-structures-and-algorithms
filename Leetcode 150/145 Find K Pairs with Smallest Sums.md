# Find K Pairs with Smallest Sums (Problem 373)

Brute force is too slow, we need an ordered data structure to store the next
best indices to start with. We use priority queue for that.

```cpp
class Solution {
    typedef pair<int, pair<int, int>> Node;
    struct mycompare {
        bool operator()(Node& p1, Node& p2) { return p1.first > p2.first; }
    } cmp;

   public:
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {
        vector<vector<int>> result;

        int M = A.size();
        int N = B.size();
        vector<int> starts(M);

        priority_queue<Node, vector<Node>, mycompare> pq(cmp);
        for (int j = 0; j < N; j++) pq.push({A[0] + B[j], {0, j}});
        while (!pq.empty() && k--) {
            auto curr = pq.top();
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            result.push_back({A[i], B[j]});
            if (i < M - 1) pq.push({A[i + 1] + B[j], {i + 1, j}});
        }
        return result;
    }
};
```
