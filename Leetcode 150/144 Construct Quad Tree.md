# Construct Quad Tree (Problem 427)

Top Down approach

```cpp
class Solution {
    typedef vector<vector<int>> Grid;

   public:
    Node* construct(Grid& grid) {
        int N = grid.size();
        return util(grid, 0, N - 1, 0, N - 1);
    }
    Node* util(Grid& grid, int t, int b, int l, int r) {
        bool isLeaf = true;
        int val = grid[t][l];
        for (int i = t; i <= b && isLeaf; i++) {
            for (int j = l; j <= r; j++) {
                if (val != grid[i][j]) {
                    isLeaf = false;
                }
            }
        }
        if (isLeaf)
            return new Node(val, isLeaf);
        else {
            int tb_m = (t + b) / 2;
            int lr_m = (l + r) / 2;
            Node* tL = util(grid, t, tb_m, l, lr_m);
            Node* tR = util(grid, t, tb_m, lr_m + 1, r);
            Node* bL = util(grid, tb_m + 1, b, l, lr_m);
            Node* bR = util(grid, tb_m + 1, b, lr_m + 1, r);
            return new Node(val, isLeaf, tL, tR, bL, bR);
        }
    }
};
```
