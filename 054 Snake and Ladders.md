# Snake and Ladders (Problem 56)

Simple Implementation with Level Order Traversal. The real concern is to deal
with problem specific details.

```cpp
class Solution {
    vector<int> get_flat_board(vector<vector<int>>& board) {
        vector<int> result(1, 0);
        int off = board.size() % 2;
        while (board.size()) {
            if ((board.size() + off) % 2)
                result.insert(result.end(), board.back().rbegin(),
                              board.back().rend());
            else
                result.insert(result.end(), board.back().begin(),
                              board.back().end());
            board.pop_back();
        }
        return result;
    }

   public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> fboard = get_flat_board(board);
        vector<int> visited = vector<int>(fboard.size(), 0);

        int end = fboard.size() - 1;
        int level = 0, pos;
        queue<int> q;
        q.push(1);
        q.push(0);
        while (q.size()) {
            pos = q.front();
            q.pop();
            if (visited[pos]) continue;
            if (pos == 0) {
                level++;
                if (q.size()) q.push(0);
                continue;
            }
            visited[pos] = 1;
            if (fboard[pos] != -1) pos = fboard[pos];
            if (pos == end) break;

            int next_max = min(pos + 6, end);
            for (int next = pos + 1; next <= next_max; next++) {
                q.push(next);
            }
        }

        return pos == end ? level : -1;
    }
};
```
