# Implement Trie (Prefix Tree) (Problem 208)

Standard Data Structure
```cpp
class Trie {
    static const int nC = 26;  // number of children
    class Node {
      public:
        Node* child[nC];
        bool isEnd;  // denotes if End of Word
        Node() {
            for (int i = 0; i < nC; i++) {
                child[i] = nullptr;
            }
            isEnd = false;
        }
    };
    Node* root;

   public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* pCrawl = root;

        for (int ind = 0; ind < word.size(); ind++) {
            int key = word[ind] - 'a';
            if (pCrawl->child[key] == nullptr) pCrawl->child[key] = new Node();
            pCrawl = pCrawl->child[key];
        }

        pCrawl->isEnd = true;
    }

    bool search(string word) {
        Node* pCrawl = root;

        for (int ind = 0; ind < word.size(); ind++) {
            int key = word[ind] - 'a';
            if (pCrawl->child[key] == nullptr) return false;
            pCrawl = pCrawl->child[key];
        }

        return pCrawl->isEnd;
    }

    bool startsWith(string prefix) {
        Node* pCrawl = root;

        for (int ind = 0; ind < prefix.size(); ind++) {
            int key = prefix[ind] - 'a';
            if (pCrawl->child[key] == nullptr) return false;
            pCrawl = pCrawl->child[key];
        }

        return true;
    }
};
```

Quick and Dirty Version
```cpp
class Trie {
    class Node {
       public:
        Node* children[26];
        bool isEnd;  // denotes if End of Word
        Node() {
            for (auto& child : children) child = nullptr;
            isEnd = false;
        }
    };
    enum OP { Insert, Search, StartsWith };
    Node* root;
    bool traverse(string& word, OP op) {
        Node* pCrawl = root;

        for (int ind = 0; ind < word.size(); ind++) {
            int key = word[ind] - 'a';
            if (pCrawl->children[key] == nullptr) {
                if (op == Insert)
                    pCrawl->children[key] = new Node();
                else
                    return false;
            }
            pCrawl = pCrawl->children[key];
        }

        switch (op) {
            case Insert:
                return pCrawl->isEnd = true, true;
            case Search:
                return pCrawl->isEnd;
            default:
                return true;
        }
    }

   public:
    Trie() { root = new Node(); }

    void insert(string word) { traverse(word, Insert); }

    bool search(string word) { return traverse(word, Search); }

    bool startsWith(string prefix) { return traverse(prefix, StartsWith); }
};
```