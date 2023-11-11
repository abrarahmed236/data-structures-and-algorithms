# Word Ladder (Problem 127)

BFS over all possible words from previous word but only consider words in the
bank into the queue.

```cpp
class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> bnk(wordList.begin(), wordList.end());
        if (bnk.find(endWord) == bnk.end()) return 0;

        vector<char> charList;
        for (char c = 'a'; c <= 'z'; c++) charList.push_back(c);

        int N = beginWord.size();
        int moves = 1;

        queue<string> Q;
        Q.push(beginWord);
        bnk.erase(beginWord);
        while (Q.size() > 0) {
            const int lvl_size = Q.size();
            for (int i = 0; i < lvl_size; i++) {
                string curr = Q.front();
                Q.pop();

                if (curr == endWord) return moves;
                for (int i = 0; i < N; i++) {
                    string temp = curr;
                    for (auto c : charList) {
                        temp[i] = c;
                        if (bnk.count(temp)) {
                            Q.push(temp);
                            bnk.erase(temp);
                        }
                    }
                }
            }
            moves++;
        }

        return 0;
    }
};
```
