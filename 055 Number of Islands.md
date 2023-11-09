# Number of Islands (Problem 200)

Basic solution using DFS

```cpp
class Solution {
    vector<vector<char>> grid;
    vector<vector<int>> visit;
    int num_islands, i_lim, j_lim;
    void dfs(int i, int j) {
        if (grid[i][j] == '0') return;
        // cout << i << " " << j << " " << num_islands << endl;
        visit[i][j] = num_islands;

        if (i - 1 >= 0 && !visit[i - 1][j]) dfs(i - 1, j);
        if (j - 1 >= 0 && !visit[i][j - 1]) dfs(i, j - 1);
        if (i + 1 < i_lim && !visit[i + 1][j]) dfs(i + 1, j);
        if (j + 1 < j_lim && !visit[i][j + 1]) dfs(i, j + 1);
    }

   public:
    int numIslands(vector<vector<char>>& grid_in) {
        grid = grid_in;

        i_lim = grid.size();
        j_lim = grid[0].size();
        visit = vector<vector<int>>(i_lim, vector<int>(j_lim, 0));
        num_islands = 0;
        int i, j;

        for (i = 0; i < i_lim; i++) {
            for (j = 0; j < j_lim; j++) {
                if (grid[i][j] == '0') continue;
                if (visit[i][j]) continue;

                ++num_islands;
                dfs(i, j);
            }
        }

        return num_islands;
    }
};
```
