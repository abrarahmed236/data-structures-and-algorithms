# Design Add and Search Words Datastructure (Problem 211)

Modified Trie implementation.  
Just change the Trie search function when the search word contains a '.'. Else
standard trie implementation.

```cpp
class WordDictionary {
    static const int nC = 26;
    class Node {
       public:
        Node* children[nC];
        bool isEnd;
        Node() {
            for (auto& childptr : children) childptr = nullptr;
            isEnd = false;
        }
    };
    Node* root;

   public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* pCrawl = root;
        for (char c : word) {
            int key = c - 'a';
            if (pCrawl->children[key] == nullptr)
                pCrawl->children[key] = new Node();
            pCrawl = pCrawl->children[key];
        }
        pCrawl->isEnd = true;
    }
    bool search_util(string word, Node* pCrawl, int ind) {
        if (ind > word.size()) return false;
        if (ind == word.size()) return pCrawl->isEnd;
        bool found = false;
        if (word[ind] == '.') {
            for (auto& child : pCrawl->children) {
                if (child != nullptr) {
                    found = search_util(word, child, ind + 1);
                    if (found) break;
                }
            }
            return found;
        } else {
            int key = word[ind] - 'a';
            if (pCrawl->children[key] == nullptr) return false;
            found = search_util(word, pCrawl->children[key], ind + 1);
        }
        return found;
    }

    bool search(string word) { return search_util(word, root, 0); }
};
```

Slightly Optimized Search
```cpp
class WordDictionary {
    static const int nC = 26;
    class Node {
       public:
        Node* children[nC];
        bool isEnd;
        Node() : children{nullptr}, isEnd(false) {}
    };
    Node* root;
    string searchWord;

   public:
    WordDictionary() {
        root = new Node();
        searchWord.reserve(64);
    }

    void addWord(string word) {
        Node* pCrawl = root;
        for (char c : word) {
            int key = c - 'a';
            Node*& child = pCrawl->children[key];
            if (child == nullptr) child = new Node();
            pCrawl = child;
        }
        pCrawl->isEnd = true;
    }
    bool search_util(Node* pCrawl, int ind) {
        if (ind > searchWord.size()) return false;
        if (ind == searchWord.size()) return pCrawl->isEnd;
        bool found = false;
        while (ind < searchWord.size()) {
            if (searchWord[ind] == '.') {
                for (Node*& child : pCrawl->children) {
                    if (child != nullptr) {
                        found = search_util(child, ind + 1);
                        if (found) break;
                    }
                }
                return found;
            } else {
                int key = searchWord[ind] - 'a';
                if (pCrawl->children[key] == nullptr) return false;
                pCrawl = pCrawl->children[key];
                ind++;
            }
        }
        return pCrawl->isEnd;
    }

    bool search(string word) {
        searchWord = word;
        return search_util(root, 0);
    }
};
```
