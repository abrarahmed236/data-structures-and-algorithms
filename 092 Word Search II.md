# Word Search II

Find the inefficiency. Working code, correct approach but TLE

```cpp
int hasher(int i, int j) { return i + (j * 100); }
class Solution {
    static const bool debug = false;
    class Trie {
       public:
        class Node {
           public:
            Node* children[26];
            bool isEnd;
            Node() : children{nullptr}, isEnd(false) {}
        };
        Node* root;
        Trie(vector<string>& words) {
            root = new Node();
            for (string& word : words) {
                push(word);
            }
        }
        void push(string& word) {
            Node* pCrawl = root;
            for (char c : word) {
                Node*& child = pCrawl->children[c - 'a'];
                if (!child) child = new Node();
                pCrawl = child;
            }
            pCrawl->isEnd = true;
        }
        bool find(string& word) {
            Node* pCrawl = root;
            for (char c : word) {
                Node*& child = pCrawl->children[c - 'a'];
                if (!child) return false;
                pCrawl = child;
            }
            return pCrawl->isEnd;
        }
    };
    vector<pair<int, int>> neighbours(const vector<vector<char>>& board, int i,
                                      int j) {
        vector<pair<int, int>> result;
        if (i - 1 >= 0) result.push_back({i - 1, j});
        if (i + 1 < board.size()) result.push_back({i + 1, j});
        if (j - 1 >= 0) result.push_back({i, j - 1});
        if (j + 1 < board[0].size()) result.push_back({i, j + 1});
        return result;
    }
    void DFS(const vector<vector<char>>& board, int i, int j,
             unordered_set<int>& visited, vector<string>& result,
             Trie::Node* pCrawl, string& curr) {
        visited.insert(hasher(i, j));
        curr.push_back(board[i][j]);
        Trie::Node* child = pCrawl->children[board[i][j] - 'a'];
        if (child) {
            if (debug) cout << "child: " << board[i][j] << ": ";
            if (child->isEnd) {
                result.push_back(curr);
                child->isEnd = false;
            }
            for (auto pos : neighbours(board, i, j)) {
                if (debug) cout << board[pos.first][pos.second] << " ";
                if (!visited.count(hasher(pos.first, pos.second))) {
                    DFS(board, pos.first, pos.second, visited, result, child,
                        curr);
                }
            }
            if (debug) cout << "\n";
        }
        curr.pop_back();
        visited.erase(hasher(i, j));
    }

   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        vector<string> result;
        Trie trie(words);

        int M = board.size();
        int N = board[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                unordered_set<int> visited;
                string curr;
                DFS(board, i, j, visited, result, trie.root, curr);
            }
        }
        sort(result.begin(), result.end());
        result.resize(
            distance(result.begin(), unique(result.begin(), result.end())));
        return result;
    }
};
```

Compare with ...
```cpp
class TrieNode {
   public:
    bool is_end;
    vector<TrieNode*> children;
    TrieNode() {
        is_end = false;
        children = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
   public:
    TrieNode* getRoot() { return root; }
    Trie(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) addWord(words[i]);
    }
    void addWord(const string& word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (cur->children[index] == NULL)
                cur->children[index] = new TrieNode();
            cur = cur->children[index];
        }
        cur->is_end = true;
    }

   private:
    TrieNode* root;
};

class Solution {
   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        set<string> result_set;
        for (int x = 0; x < board.size(); ++x)
            for (int y = 0; y < board[0].size(); ++y)
                findWords(board, x, y, root, "", result_set);

        vector<string> result;
        for (auto it : result_set) result.push_back(it);
        return result;
    }

   private:
    void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root,
                   string word, set<string>& result) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() ||
            board[x][y] == ' ')
            return;

        if (root->children[board[x][y] - 'a'] != NULL) {
            word = word + board[x][y];
            root = root->children[board[x][y] - 'a'];
            if (root->is_end) result.insert(word);
            char c = board[x][y];
            board[x][y] = ' ';
            findWords(board, x + 1, y, root, word, result);
            findWords(board, x - 1, y, root, word, result);
            findWords(board, x, y + 1, root, word, result);
            findWords(board, x, y - 1, root, word, result);
            board[x][y] = c;
        }
    }
};
```