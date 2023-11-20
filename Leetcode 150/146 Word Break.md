# Word Break (Problem 139)

Brute force Recursive (TLE) O(2^N)

```cpp
class Solution {
   public:
    bool util(string& s, int pos, vector<string>& words) {
        cout << pos << ": " << s.substr(pos) << endl;
        if (pos == s.size()) return true;
        if (pos > s.size()) return false;
        bool found = false;
        for (auto& word : words) {
            if(pos + word.size() > s.size()) continue;
            int pos1 = s.find(word, pos);
            if (pos1 == pos) found = util(s, pos + word.size(), words);
            if (found) return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        auto cmp = [](string& a, string& b) {
            if(a.size() == b.size()) return a < b;
            else return a.size() > b.size();
        };
        sort(wordDict.begin(), wordDict.end(), cmp);
        for(auto& word: wordDict) cout << word << " ";
        cout << endl;
        return util(s, 0, wordDict);
    }
};
```

1D DP solution, O(N^2) time ? `//revisit`

|     | a   | p   | p   | l   | e   | p   | e   | n   | a   | p   | p   | l   | e   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 1   | 0   | 0   | 1   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 1   | 0   | 0   | 1   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 1   | 0   | 0   | 1   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 1   | 0   | 0   | 1   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 1   | 0   | 0   | 1   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 1   | 0   | 0   | 1   | 0   | 0   | 0   | 0   | 1   |

```cpp
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int N = s.size();
        vector<int> dp(N + 1);
        dp[0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    if (dict.find(s.substr(j, i - j)) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[N];
    }
};
```
