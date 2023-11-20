# Substring with concatenation of all words (Problem 30)

Working solution with maps. (TLE)

```cpp
class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int N = s.size();
        int word_len = words[0].size();
        int window_size = words.size() * word_len;

        unordered_map<string, int> expected_count;
        for (string word : words) expected_count[word]++;

        for (int i = 0; i < N - window_size + 1; i++) {
            unordered_map<string, int> current_count;
            for (int j = 0; j < window_size; j += word_len) {
                string subs = s.substr(j + i, word_len);
                current_count[subs]++;
            }
            bool accepted = true;
            for (string word : words) {
                if (current_count[word] != expected_count[word]) {
                    accepted = false;
                    break;
                }
            }
            if (accepted) result.push_back(i);
        }
        return result;
    }
};
```

Another working solution with maps (Pretty slow)

```cpp
class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int N = s.size();
        const int word_len = words[0].size();
        const int num_words = words.size();
        int window_size = num_words * word_len;

        unordered_map<string, int> expected_count;
        for (string word : words) expected_count[word]++;

        for (int i = 0; i <= N - window_size; i++) {
            unordered_map<string, int> current_count = expected_count;
            int found_words = 0;
            for (int j = i; j < N; j += word_len) {
                string subs = s.substr(j, word_len);
                if (current_count[subs] > 0) {
                    found_words++;
                    current_count[subs]--;
                } else
                    break;
            }
            if (found_words == num_words) result.push_back(i);
        }
        return result;
    }
};
```

Much improved, sliding window solution. Basic idea is the same, but the
implementation takes care of specific inefficiencies.

```cpp
class Solution {
   private:
    unordered_map<string, int> counter;
    unordered_map<string, int> used;
    int matched_words;

    void push(string& s) {
        if (counter.count(s)) {
            used[s]++;
            if (used[s] == counter[s]) {
                matched_words++;
            } else if (used[s] == counter[s] + 1) {
                matched_words--;
            }
        }
    }
    void pop(string& s) {
        if (counter.count(s)) {
            used[s]--;
            if (used[s] == counter[s]) {
                matched_words++;
            } else if (used[s] == counter[s] - 1) {
                matched_words--;
            }
        }
    }

   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int N = s.size();
        const int word_len = words[0].size();
        const int num_words = words.size();
        int window_size = num_words * word_len;

        counter.clear();
        for (string word : words) counter[word]++;

        for (int off = 0; off < word_len; off++) {
            used.clear();
            matched_words = 0;
            for (int pos = off; pos < off + window_size; pos += word_len) {
                string subs = s.substr(pos, word_len);
                push(subs);
            }
            if (matched_words == counter.size()) result.push_back(off);
            for (int beg = off, pos = off + window_size; pos <= N - word_len;
                 pos += word_len, beg += word_len) {
                string dels = s.substr(beg, word_len);
                pop(dels);
                string adds = s.substr(pos, word_len);
                push(adds);
                if (matched_words == counter.size()) result.push_back(beg + word_len);
            }
        }
        return result;
    }
};
```

Why better ? Because ...

Then we have a similarly well performing trie solution. But it is honestly not
worth it due to the amount of effort it takes and when unordered_map can do the
job implementing a custom trie is not very smart

```cpp
const bool debug = false;

const static int ALPHABET_SIZE = 26;

class TrieNode {
   public:
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    int expectedCnt;
    int actualCnt;
    TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
        expectedCnt = 0;
        actualCnt = 0;
    }
    void init() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
        expectedCnt = 0;
        actualCnt = 0;
    }
};

class Trie {
   private:
    void destroy(TrieNode *root) {
        if (!root) return;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root->children[i]) destroy(root->children[i]);
        }

        delete root;
    }

   public:
    TrieNode *root;
    Trie() { root = new TrieNode; }
    ~Trie() { destroy(root); }
    int insert(string &key) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            // if (debug) cout << "inserted: " << key[i] << endl;
            int index = key[i] - 'a';
            if (pCrawl->children[index] == nullptr) {
                pCrawl->children[index] = new TrieNode();
                // (*pCrawl->children[index]).init();
            }

            pCrawl = pCrawl->children[index];
        }

        pCrawl->isEndOfWord = true;
        pCrawl->expectedCnt++;
        // if (debug) cout << "inserted: " << key << endl;
        return pCrawl->expectedCnt;
    }
    TrieNode *search(string &key) {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return nullptr;  // indicates not found

            pCrawl = pCrawl->children[index];
        }

        // if (debug) cout << "found: " << key << endl;

        if (pCrawl->isEndOfWord)
            return pCrawl;
        else
            return nullptr;
    }

    void clear_counters(TrieNode *rt) {
        if (!rt) return;
        rt->actualCnt = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (rt->children[i]) clear_counters(rt->children[i]);
        }
    }
    // void clear_counter() { clear_util(root); }
    void clear(TrieNode *rt) {
        if (rt == nullptr) return;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (rt->children[i] != nullptr) {
                // if(debug) cout << (char)('a' + i);
                clear(rt->children[i]);
            }
        }
        if (rt != root)
            delete rt;
        else
            rt->init();
    }
};

class Solution {
   private:
    Trie trie;
    int matched_words;

    void push(string &s) {
        TrieNode *ret = trie.search(s);
        if (ret) {
            ret->actualCnt++;
            if (ret->actualCnt == ret->expectedCnt) {
                matched_words++;
            } else if (ret->actualCnt == ret->expectedCnt + 1) {
                matched_words--;
            }
        }
    }
    void pop(string &s) {
        TrieNode *ret = trie.search(s);
        if (ret) {
            ret->actualCnt--;
            if (ret->actualCnt == ret->expectedCnt) {
                matched_words++;
            } else if (ret->actualCnt == ret->expectedCnt - 1) {
                matched_words--;
            }
        }
    }

   public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result;
        int N = s.size();
        const int word_len = words[0].size();
        const int num_words = words.size();
        int window_size = num_words * word_len;

        trie.clear(trie.root);
        int expected_words = 0;
        for (string &word : words) {
            int ret = trie.insert(word);
            if (ret == 1) expected_words++;
        }

        for (int off = 0; off < word_len; off++) {
            // trie.clear_counter();
            trie.clear_counters(trie.root);
            matched_words = 0;
            for (int pos = off; pos < off + window_size; pos += word_len) {
                string subs = s.substr(pos, word_len);
                push(subs);
            }
            if (matched_words == expected_words) result.push_back(off);
            for (int beg = off, pos = off + window_size; pos <= N - word_len;
                 pos += word_len, beg += word_len) {
                string dels = s.substr(beg, word_len);
                pop(dels);
                string adds = s.substr(pos, word_len);
                push(adds);
                if (matched_words == expected_words)
                    result.push_back(beg + word_len);
            }
        }
        return result;
    }
};
```
