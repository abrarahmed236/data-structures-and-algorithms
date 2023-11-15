# Word Search (Problem 79)

Brute force backtracking, works but takes too long (TLE)

```cpp
typedef struct Adj {
    int i;
    int j;
} Adj;
class Solution {
    int M, N;
    vector<vector<char>> board;
    vector<vector<int>> visited;
    vector<Adj> get_adj(int i, int j) {
        vector<Adj> result;
        if (i > 0) result.push_back({i - 1, j});
        if (j > 0) result.push_back({i, j - 1});
        if (i + 1 < M) result.push_back({i + 1, j});
        if (j + 1 < N) result.push_back({i, j + 1});

        return result;
    }
    bool util(int i, int j, string word) {
        if (board[i][j] != word.back()) return false;
        if (word.size() == 1) return true;
        word.pop_back();
        visited[i][j] = true;
        for (auto n : get_adj(i, j)) {
            if (!visited[n.i][n.j]) {
                if (util(n.i, n.j, word)) return true;
            }
        }
        visited[i][j] = false;
        return false;
    }

   public:
    bool exist(vector<vector<char>>& board_, string word) {
        reverse(word.begin(), word.end());
        board = board_;
        M = board.size();
        N = board[0].size();
        visited = vector<vector<int>>(M, vector<int>(N, 0));
        bool found = false;
        for (int i = 0; i < M && !found; i++) {
            for (int j = 0; j < N && !found; j++) {
                found = util(i, j, word);
            }
        }
        return found;
    }
};
```

With a minor fix this really bad solution works. It takes quite a long time
though and there are better solutions possilbe.

```cpp
typedef struct Adj {
    int i;
    int j;
} Adj;
class Solution {
    int M, N;
    vector<vector<char>> board;
    vector<vector<int>> visited;
    vector<Adj> get_adj(int i, int j) {
        vector<Adj> result;
        if (i > 0) result.push_back({i - 1, j});
        if (j > 0) result.push_back({i, j - 1});
        if (i + 1 < M) result.push_back({i + 1, j});
        if (j + 1 < N) result.push_back({i, j + 1});

        return result;
    }
    bool util(int i, int j, string word) {
        if (board[i][j] != word.back()) return false;
        if (word.size() == 1) return true;
        word.pop_back();
        visited[i][j] = true;
        for (auto n : get_adj(i, j)) {
            if (!visited[n.i][n.j]) {
                if (util(n.i, n.j, word)) return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
    bool sanity_check(string word) {
        char st[256]{0};
        for (auto& v : board) {
            for (auto& c : v) {
                st[c] = 1;
            }
        }
        for (char c : word)
            if (!st[c]) return false;
        return true;
    }

   public:
    bool exist(vector<vector<char>>& board_, string word) {
        reverse(word.begin(), word.end());
        board = board_;
        M = board.size();
        N = board[0].size();
        if (!sanity_check(word)) return false;
        visited = vector<vector<int>>(M, vector<int>(N, 0));
        bool found = false;
        for (int i = 0; i < M && !found; i++) {
            for (int j = 0; j < N && !found; j++) {
                found = util(i, j, word);
            }
        }
        return found;
    }
};
```

More or less the same method, but much better written code

```cpp
class Solution {
    typedef vector<vector<char>> Board;
    typedef vector<vector<int>> Visited;
    inline bool validPos(Board& board, int i, int j) {
        return i >= 0 && j >= 0 && i < board.size() && j < board[0].size();
    }
    bool util(int i, int j, string& word, int idx, vector<pair<int, int>>& dirs,
              Visited& visited, Board& board) {
        if (board[i][j] != word[idx]) return false;
        if (word.size() - 1 == idx) return true;
        visited[i][j] = true;
        for (auto [x, y] : dirs) {
            if (validPos(board, i + x, j + y) && !visited[i + x][j + y]) {
                if (util(i + x, j + y, word, idx + 1, dirs, visited, board))
                    return true;
            }
        }
        visited[i][j] = false;
        return false;
    }

   public:
    bool exist(Board& board, string word) {
        // prune on the basis of all characters of word being present in board
        vector<int> st(256);
        for (auto& v : board) {
            for (auto& c : v) {
                st[c]++;
            }
        }
        for (auto& c : word) st[c]--;
        for (auto& n : st)
            if (n < 0) return false;

        // initialize useful stuff
        int M = board.size();
        int N = board[0].size();
        Visited visited(M, vector<int>(N));
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // DFS from each starting point
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (util(i, j, word, 0, dirs, visited, board)) return true;
            }
        }

        return false;
    }
};
```
